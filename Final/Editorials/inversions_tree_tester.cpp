#undef NDEBUG
#ifdef ssu1
//#define _GLIBCXX_DEBUG
#endif

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

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

int readInt(int l, int r){
    int x;
    if(scanf("%d", &x) != 1){
        fprintf(stderr, "Expected int in range [%d, %d], but haven't found!", l, r);
        throw;
    }
    if(!(l <= x && x <= r)){
        fprintf(stderr, "Expected int in range [%d, %d], but found %d!", l, r, x);
        throw;
    }
    return x;
}
int readInt(int l, int r, string name){
    int x;
    if(scanf("%d", &x) != 1){
        fprintf(stderr, "Expected int %s in range [%d, %d], but haven't found!", name.c_str(), l, r);
        throw;
    }
    if(!(l <= x && x <= r)){
        fprintf(stderr, "Expected int %s in range [%d, %d], but found %d!", name.c_str(), l, r, x);
        throw;
    }
    return x;
}

struct mtree{
    vector<int> vals, t;

    mtree(){}

    void add(int val, int dx){
        int idx = int(lower_bound(all(vals), val) - vals.begin());
        assert(vals[idx] == val);
        for(; idx < sz(t); idx = (idx | (idx + 1)))
            t[idx] += dx;
    } 

    int less(int x){
        int r = (int)(lower_bound(all(vals), x) - vals.begin()) - 1, ans = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1)
            ans += t[r];
        return ans;
    }
};

struct madd{
    vector<int> a, ba, dv;
    int block;
    madd(int n){
        block = (int)(sqrt(n) + 2);
        a.assign(n, 0), dv.assign(n, 0);
        ba.assign((n + block - 1) / block, 0);
        forn(i, n)
            dv[i] = i / block;
    }

    void inc(int i, int dx){
        a[i] += dx;
        ba[dv[i]] += dx;
    }

    int sum(int l, int r){
        int ans = 0;
        for(int i = l; i <= r;){
            if(dv[i] * block == i && i + block - 1 <= r){
                ans += ba[dv[i]];
                i += block;
            }else{
                ans += a[i];
                i++;
            }
        }
        return ans;
    }
};

const int NMAX = 100010;

int lf[NMAX], rg[NMAX], pos[NMAX], ord[NMAX], sa[NMAX], n, szord;

mtree t[4 * NMAX];

int nx[2 * NMAX], fs[NMAX];
pt e[2 * NMAX];

void dfs(int v, int pv){
    ord[szord++] = v;
    lf[v] = rg[v] = pos[v] = szord - 1;
    for(int i = fs[v]; i >= 0; i = nx[i]){
        int u = e[i].Y;
        if(u != pv){
            dfs(u, v);
            rg[v] = rg[u];
        }
    }
}

void build(int idx, int l, int r){
    if(l == r){
        sort(all(t[idx].vals));
        t[idx].vals.erase(unique(all(t[idx].vals)), t[idx].vals.end());
        t[idx].t.assign(sz(t[idx].vals), 0);
        return;
    }

    int mid = (l + r) >> 1;
    build(2 * idx + 1, l, mid);
    build(2 * idx + 2, mid + 1, r);

    t[idx].vals.assign(sz(t[2 * idx + 1].vals) + sz(t[2 * idx + 2].vals), 0);
    merge(all(t[2 * idx + 1].vals), all(t[2 * idx + 2].vals), t[idx].vals.begin());

    t[idx].vals.erase(unique(all(t[idx].vals)), t[idx].vals.end());
    t[idx].t.assign(sz(t[idx].vals), 0);
}

void fadd(int value, int pos, int idx, int l, int r){
    if(l == r){
        t[idx].vals.pb(value);
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid)
        fadd(value, pos, 2 * idx + 1, l, mid);
    else
        fadd(value, pos, 2 * idx + 2, mid + 1, r);
}

void add(int value, int dx, int pos, int idx, int l, int r){
    t[idx].add(value, dx);
    if(l == r)
        return;
    int mid = (l + r) >> 1;
    if(pos <= mid)
        add(value, dx, pos, 2 * idx + 1, l, mid);
    else
        add(value, dx, pos, 2 * idx + 2, mid + 1, r);
}

int query(int x, int l, int r, int idx, int tl, int tr){
    if(l == tl && r == tr)
        return t[idx].less(x);
    int mid = (tl + tr) >> 1, ans = 0;
    if(l <= mid)
        ans += query(x, l, min(r, mid), 2 * idx + 1, tl, mid);
    if(r >= mid + 1)
        ans += query(x, max(l, mid + 1), r, 2 * idx + 2, mid + 1, tr);
    return ans;
}

map<int, int> cadd[NMAX];
int bad[NMAX];
madd data(NMAX);

void calc(int v, int pv){
    if(!bad[v])
        data.inc(sa[v], +1);
    else{
        for(auto i = cadd[v].begin(); i != cadd[v].end(); ++i){
            i->Y = data.sum(i->X + 1, NMAX - 1);
        }
    }
    for(int i = fs[v]; i >= 0; i = nx[i]){
        int u = e[i].Y;
        if(u != pv){
            calc(u, v); 
        }
    }
    if(!bad[v])
        data.inc(sa[v], -1);
}

inline bool ispar(int p, int v){
    return lf[p] <= lf[v] && rg[v] <= rg[p];
}

inline bool cmp(int v, int u){
    return (rg[v] - lf[v] > rg[u] - lf[u]) || (rg[v] - lf[v] == rg[u] - lf[u] && v < u);
}

int main() {
#ifdef ssu1
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
#endif

#undef ssu1

    n = readInt(1, 100000, "n");
    int m = readInt(1, 100000, "m");
    forn(i, n){
#ifndef ssu1
        sa[i] = readInt(1, 100000, "t_i");
#else
        sa[i] = rand() % 100000 + 1;
#endif
    }
    forn(i, n - 1){
        int v, u;
#ifndef ssu1
        v = readInt(1, n, "v[i]") - 1;
        u = readInt(1, n, "u[i]") - 1;
#else
        v = i + 1, u = rand() % (i + 1);
#endif
        assert(v != u);

        e[i] = mp(v, u);
        e[i + n - 1] = mp(u, v);
    }

    memset(fs, -1, sizeof fs);
    forn(i, 2 * (n - 1)){
        nx[i] = fs[e[i].X];
        fs[e[i].X] = i;
    }

    vector<pt> qs(m);
    forn(qi, m){
#ifndef ssu1
        qs[qi].X = readInt(1, n, "qv") - 1;
        qs[qi].Y = readInt(1, 100000, "qval");
#else
        qs[qi].X = rand() % n;
        qs[qi].Y = 100000 - qi;
#endif
    }

    dfs(0, -1);
    assert(szord == n);

    forn(v, n)
        fadd(sa[v], pos[v], 0, 0, n - 1);
    forn(i, m){
        int v = qs[i].X, nv = qs[i].Y;
        fadd(nv, pos[v], 0, 0, n - 1);
    }
    build(0, 0, n - 1);

    forn(v, n)
       add(sa[v], +1, pos[v], 0, 0, n - 1); 

    li ans = 0;
    forn(v, n){
        ans += query(sa[v], lf[v], rg[v], 0, 0, n - 1); 
    }

#ifdef ssu1
    cerr << "\nTime = " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif    

    printf("%lld\n", ans);


    vector<int> bsa(n);
    forn(v, n)
        bsa[v] = sa[v];

    const int B = 1000;
    vector<int> dans(m), vx;

    for(int l = 0; l < m; l += B){
        int r = min(m - 1, l + B - 1);

        vx.clear();
        fori(i, l, r){
            int v = qs[i].X, nv = qs[i].Y;
            bad[v] = true;
            cadd[v][nv] = 0;
            cadd[v][sa[v]] = 0;
            vx.pb(v);
        }

        sort(all(vx), cmp);
        vx.erase(unique(all(vx)), vx.end());

        calc(0, -1); 

        fori(i, l, r){
            int v = qs[i].X, nv = qs[i].Y, cv = sa[v];
            dans[i] = -cadd[v][cv];
            dans[i] += cadd[v][nv];
            forn(j, sz(vx)){
                int pv = vx[j];
                if(pv == v)
                    break;
                if(ispar(pv, v) && sa[pv] > cv)
                    dans[i]--;
                if(ispar(pv, v) && sa[pv] > nv)
                    dans[i]++;
            } 
            sa[v] = nv;
        }
        //clear
        fori(i, l, r){
            cadd[qs[i].X].clear();
            bad[qs[i].X] = false;
        }
    }

#ifdef ssu1
    cerr << "\nTime = " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif    

    forn(v, n)
        sa[v] = bsa[v];

    forn(qi, m){
        int v = qs[qi].X, val = qs[qi].Y;
        ans -= query(sa[v], lf[v], rg[v], 0, 0, n - 1);
        add(sa[v], -1, pos[v], 0, 0, n - 1);

        sa[v] = val;
        add(sa[v], +1, pos[v], 0, 0, n - 1);
        ans += query(sa[v], lf[v], rg[v], 0, 0, n - 1);
        ans += dans[qi];
        printf("%lld\n", ans);
    }
#ifdef ssu1
    cerr << "\nTime = " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif    
    return 0;
}