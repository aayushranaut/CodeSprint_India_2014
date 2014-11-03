#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<PII>     VPII;
#define MM(a,x) memset(a,x,sizeof(a));
#define ALL(x)  (x).begin(), (x).end()
#define P(x)    cerr<<"["#x<<" = "<<(x)<<"]"<<endl;
#define PP(x,i) cerr<<"["#x<<i<<" = "<<x[i]<<"]"<<endl;
#define P2(x,y) cerr<<"["#x" = "<<(x)<<", "#y" = "<<(y)<<"]"<<endl;
#define TM(a,b) cerr<<"["#a" -> "#b": "<<1e3*(b-a)/CLOCKS_PER_SEC<<"ms]\n";
#define UN(v)   sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _ {_() {ios_base::sync_with_stdio(0);}} _;
template<class T> string tostring(T x, int len = 0, char c = '0') {stringstream ss; ss << x; string r = ss.str(); if(r.length() < len) r = string(len - r.length(), c) + r; return r;}
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
template<class T> void PV(T a, T b, int n = 0, int w = 0, string s = " ") {int c = 0; while(a != b) {cout << tostring(*a++, w, ' '); if(a != b && (n == 0 || ++c % n)) cout << s; else cout << endl;}}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 111111;
const int M = 501;

int n, m;
int a[N];
int b[N];
int c[N];
int d[N];
int dp[N][M];

vector<int> g[2 * N];

int f[2][N];

int brute() {
    MM(f, 0);
    for(int i = 1; i <= n; i++) {
        int to = i & 1;
        int from = 1 - to;
        fill(&f[to][0], &f[to][N], 0);
        for(int j = 1; j <= m; j++) {
            if(c[i] == d[j]) {
                f[to][j] = f[from][j - 1] + 1;
            } else {
                f[to][j] = max(f[to][j - 1], f[from][j]);
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= m; i++) chmax(res, f[n & 1][i]);
    return res;
}


bool check(vector<int> LCS) {
    int p1 = 0;
    for(int i = 1; i <= n; i++) {
        if(p1 < LCS.size() && c[i] == LCS[p1]) p1++;
    }

    int p2 = 0;
    for(int i = 1; i <= m; i++) {
        if(p2 < LCS.size() && d[i] == LCS[p2]) p2++;
    }
    return (p1 == LCS.size() && p2 == LCS.size());
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= m; i++) cin >> d[i];

    vector<int> v;
    for(int i = 1; i <= n; i++) v.pb(c[i]);
    for(int i = 1; i <= m; i++) v.pb(d[i]);
    UN(v);
    for(int i = 1; i <= n; i++) a[i] = lower_bound(ALL(v), c[i]) - v.begin();
    for(int i = 1; i <= m; i++) b[i] = lower_bound(ALL(v), d[i]) - v.begin();
    for(int i = 1; i <= m; i++) g[b[i]].pb(i);

    MM(dp, 0x3f);
    for(int i = 0; i <= n; i++) dp[i][0] = 0;

    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 500; j++) {
            dp[i][j] = dp[i - 1][j];
            int t = lower_bound(ALL(g[a[i]]), dp[i - 1][j - 1] + 1) - g[a[i]].begin();
            if(t != g[a[i]].size()) chmin(dp[i][j], g[a[i]][t]);
            if(dp[i][j] != inf) chmax(res, j);
        }

    int pi = n, pj = dp[n][res];

    vector<int> ans;
    int cnt = 0;
    while(1) {
        while(a[pi] != b[pj]) {
            pi--;
        }
        ans.pb(c[pi]);
        cnt++;
        if(cnt == res) break;
        pi--, pj = dp[pi][res - cnt];
    }
    reverse(ALL(ans));
    //assert(res == ans.size());
    //assert(res == min(brute(), 500));
    //assert(check(ans));
    PV(ALL(ans));
    return 0;
}