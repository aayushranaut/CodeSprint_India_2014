#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wmissing-prototypes"
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wmissing-variable-declarations"
#pragma clang diagnostic ignored "-Wsign-compare"
#pragma clang diagnostic ignored "-Wsign-conversion"

#ifdef ssu1
#define _GLIBCXX_DEBUG
#endif
#undef NDEBUG

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <limits>

using namespace std;

template<typename Type>
Type Read(Type lowest, Type greatest, string name = "") {
  Type input;
  bool readed = false;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
  if (typeid(Type) == typeid(int)) {
    readed = (scanf("%d", &input) == 1);
  } else if (typeid(Type) == typeid(long long)) {
    readed = (scanf("%lld", &input) == 1);
  } else if (typeid(Type) == typeid(long long)) {
    readed = (scanf("%lf", &input) == 1);
  } else if (typeid(Type) == typeid(size_t)) {
    unsigned long long tmp;
    readed = (scanf("%llu", &tmp) == 1);
    input = static_cast<size_t>(tmp);
  } else 
    throw;
#pragma clang diagnostic pop
  if (!readed) {
    if (!name.empty()) {
      cerr << "Variable " << name << endl;
    }
    cerr << "Expected type: " << typeid(Type).name() << endl;
    cerr << "Nothing found!" << endl;
    throw;
  }
  if (input < lowest || input > greatest) {
    if (!name.empty()) {
      cerr << "Variable " << name << endl;
    }
    cerr << "Expected value in [" << lowest << ";" << greatest << "]\n"; 
    cerr << "Found: " << input << endl;
    throw;
  }
  return input;
}

int n, m;

struct Ex {
  int l, r, d, c, s;
};

bool operator < (const Ex& o1, const Ex& o2) {
  return o1.l < o2.l;
}

struct UpperEnvelope {
  UpperEnvelope() {}
  UpperEnvelope(int left, int right) {
    left_ = left;
    right_ = right;
    Add(Seg{left, right, 0, 0});
  }
  struct Seg {
    int l, r;
    //a * x + b, x in [l, r]
    long long a, b;
    bool operator < (const Seg& other) const {
      return l < other.l;
    }
    long long Y(long long x) const {
      return a * x + b;
    }
  };
  void Add(Seg obj) {
    assert(s_.count(obj) == 0);
    assert(ra_.count(obj.a) == 0);
    s_.insert(obj);
    ra_[obj.a] = obj;
  }
  void Erase(Seg obj) {
    assert(s_.count(obj));
    assert(ra_.count(obj.a));
    s_.erase(obj);
    ra_.erase(obj.a);
  }
  bool Better(Seg a, Seg b, int x) {
    return a.Y(x) > b.Y(x);
  }
  bool Better(Seg a, Seg b) {
    return Better(a, b, b.l) && Better(a, b, b.r);
  }
  bool Process(Seg& s1, Seg s2, vector<Seg>& del, vector<Seg>& add) {
    if (Better(s1, s2)) {
      del.push_back(s2);
      return false;
    }
    if (Better(s1, s2, s2.l) || Better(s1, s2, s2.r)) {
      del.push_back(s2);
      int lf = s2.l, rg = s2.r;
      while(rg - lf > 1) {
        int mid = (lf + rg) / 2;
        if (Better(s1, s2, mid) == Better(s1, s2, s2.l))
          lf = mid;
        else
          rg = mid;
      }
      if (Better(s1, s2, s2.l))
        s2.l = lf + 1, s1.r = min(s1.r, lf);
      else
        s2.r = lf, s1.l = max(s1.l, lf + 1);
      assert(s2.l <= s2.r);
      add.push_back(s2);
    }
    return true;
  }
  void Add(long long a, long long b) {
    Seg current = {left_, right_, a, b};
    auto rit = ra_.lower_bound(a);
    auto it = s_.lower_bound(rit->second);
    auto leftit = it, rightit = it;
    vector<Seg> del, add;
    while (leftit != s_.begin()) {
      leftit--;
      if (Process(current, *leftit, del, add))
        break;
    }
    Process(current, *it, del, add);
    while ((++rightit) != s_.end()) {
      if (Process(current, *rightit, del, add))
        break;
    }
    for (Seg s : del)
      Erase(s);
    for (Seg s : add)
      Add(s);
    if (!del.empty()) {
      assert(current.l <= current.r);
      Add(current);
    }
  }
  long long Y(int x) {
    assert(left_ <= x && x <= right_);
    set<Seg>::iterator it = s_.upper_bound(Seg{x, -1, -1, -1}); 
    it--;
    return it->Y(x);
  }
  set<Seg> s_;
  map<long long, Seg> ra_;
  int left_, right_;
};

const int kMaxN = 100010;

UpperEnvelope t[4 * kMaxN];

void Build(int idx, int l, int r) {
  t[idx] = UpperEnvelope(l, r);
  if (l == r)
    return;
  int mid = (l + r) / 2;
  Build(2 * idx + 1, l, mid);
  Build(2 * idx + 2, mid + 1, r);
}

void Add(int l, int r, long long a, long long b, int idx, int tl, int tr) {
  if (l == tl && r == tr) {
    t[idx].Add(a, b);
    return;
  }
  int mid = (tl + tr) / 2;
  if (l <= mid)
    Add(l, min(r, mid), a, b, 2 * idx + 1, tl, mid);
  if (r >= mid + 1)
    Add(max(l, mid + 1), r, a, b, 2 * idx + 2, mid + 1, tr);
}

long long Value(int x, int idx, int tl, int tr) {
  if (tl == tr)
    return t[idx].Y(x);
  long long answer = t[idx].Y(x);
  int mid = (tl + tr) / 2;
  if (x <= mid)
    answer = max(answer, Value(x, 2 * idx + 1, tl, mid));
  else
    answer = max(answer, Value(x, 2 * idx + 2, mid + 1, tr));
  return answer;
}

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
  //assert(freopen("output.txt", "wt", stdout));
#endif
 n = Read<int>(1, 100000, "n");
 m = Read<int>(1, 100000, "m");
 vector<Ex> ex;
 for (int i = 0; i < m; ++i) {
   Ex cur;
   cur.l = Read<int>(1, n, "l") - 1;
   cur.r = Read<int>(1, n, "r") - 1;
   cur.d = Read<int>(1, n, "d") - 1;
   cur.c = Read<int>(1, 10000, "c");
   cur.s = Read<int>(1, 10000, "s");
   ex.push_back(cur);
   assert(cur.l <= cur.r && cur.r <= cur.d);
 }
 sort(ex.begin(), ex.end());
 Build(0, 0, n);
 vector<long long> d(n + 1);
 int j = 0;
 for (int i = 0; i < n; ++i) {
   d[i] = max(d[i], Value(i, 0, 0, n));
   d[i + 1] = max(d[i + 1], d[i]);
   while (j < m && ex[j].l == i) {
     Add(ex[j].r + 1, 
         ex[j].d + 1, 
         ex[j].c, 
         ex[j].s - ex[j].c * 1LL * ex[j].l + d[i],
         0,
         0,
         n);
     j++;
   }
 }
 cout << max(d[n], Value(n, 0, 0, n)) << endl;
#ifdef ssu1
  cerr << "Time = " << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}