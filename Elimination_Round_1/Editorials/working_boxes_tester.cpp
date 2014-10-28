#include <map>
#include <set>
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
typedef pair<LL, LL>    PLL;
typedef vector<PLL>     VPLL;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<PII>     VPII;
typedef vector<VI>      VVI;
typedef vector<VPII>    VVPII;
#define MM(a,x) memset(a,x,sizeof(a));
#define ALL(x)  (x).begin(), (x).end()
#define P(x)     cerr<<"["#x<<" = "<<(x)<<"]"<<endl;
#define P2(x,y)  cerr<<"["#x" = "<<(x)<<", "#y" = "<<(y)<<"]"<<endl;
#define P3(x,y,z)cerr<<"["#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<"]"<<endl;
#define PP(x,i)  cerr<<"["#x<<i<<" = "<<x[i]<<"]"<<endl;
#define TM(a,b)  cerr<<"["#a" -> "#b": "<<1e3*(b-a)/CLOCKS_PER_SEC<<"ms]\n";
#define UN(v)   sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _ {_() {ios_base::sync_with_stdio(0);}} _;
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
template<class T> string tostring(T x, int len = 0, char c = '0') {stringstream ss; ss << x; string r = ss.str(); if(r.length() < len) r = string(len - r.length(), c) + r; return r;}
template<class T> void PV(T a, T b, int n = 0, int w = 0, string s = " ") {int c = 0; while(a != b) {cout << tostring(*a++, w, ' '); if(a != b && (n == 0 || ++c % n)) cout << s; else cout << "\n"; cout.flush();}}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 111;

int n, T;
int w[N];
int s[N];

int dp[N][N];

int check(int c) {
    MM(dp, 0x3f);
    for(int i = 0; i < n; i++) dp[i][i] = 0;
    for(int l = 2; l <= n; l++)
        for(int i = 0; i < n; i++) {
            int j = i + l - 1;
            if(j >= n) break;

            for(int k = i; k < j; k++) {
                int cost = (s[k + 1] - s[i]) * (k - i + 1) + (s[j + 1] - s[k + 1]) * (j - k);
                cost = max(cost - c, 0);
                chmin(dp[i][j], dp[i][k] + dp[k + 1][j] + cost);
            }
        }
    return dp[0][n - 1] <= T;
}

int main() {
    cin >> n >> T;
    assert(1 <= n && n <= 100);
    assert(1 <= T && T <= 1e6);
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        assert(1 <= w[i] && w[i] <= 100);
        s[i + 1] = s[i] + w[i];
    }

    int L = 0, R = inf;

    while(L < R) {
        int M = (L + R) / 2;

        if(check(M)) {
            R = M;
        } else {
            L = M + 1;
        }
    }

    cout << L << endl;

    return 0;
}