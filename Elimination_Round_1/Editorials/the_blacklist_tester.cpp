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
typedef vector<int>     VI;
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
const int N = 20;
const int K = 10;


int n, k;
int s[K + 1][N + 1];
int dp[N + 1][1 << K];

int main() {
    cin >> n >> k;
    assert(1 <= n and n <= 20);
    assert(1 <= k and k <= 10);
    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;

            s[i][j + 1] = s[i][j] + x;
        }

    MM(dp, 0x3f);
    dp[0][0] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 1 << k; j++)
            for(int x = 0; x < k; x++) {
                if(j >> x & 1) continue;
                for(int y = i; y < n; y++) {
                    int w = s[x][y + 1] - s[x][i];
                    chmin(dp[y + 1][j | (1 << x)], dp[i][j] + w);
                }
            }
    int res = inf;
    for(int i = 0; i < 1 << k; i++) chmin(res, dp[n][i]);
    cout << res << endl;
    return 0;
}