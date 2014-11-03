#include <bits/stdc++.h>
using namespace std;

#define s(n)            scanf("%d",&n)
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define ss(n)           scanf("%s",n)
#define pls(x)          cout << x << " "
#define pln(x)          cout << x << "\n"
#define pis(x)          printf("%d ", x)
#define pin(x)          printf("%d\n", x)
#define pnl             printf("\n")
#define dbn             cerr << "\n"
#define dbg(x)          cerr << #x << " : " << x << " "
#define dbs(x)          cerr << x << " "
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define rep(i,n)        FOR(i,0,n-1)
#define foreach(v,c)    for(__typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp              make_pair
#define FF              first
#define SS              second
#define xx              first
#define yy              second.first
#define zz              second.second
#define pb              push_back
#define fill(a,v)       memset(a,v,sizeof(a))
#define all(x)          x.begin(),x.end()
#define sz(v)           ((int)(v.size()))
#define INF             (int)1e9
#define LINF            (long long)1e18
#define EPS             1e-9
#define maX(a,b)        ((a)>(b)?(a):(b))
#define miN(a,b)        ((a)<(b)?(a):(b))
#define abS(x)          ((x)<0?-(x):(x))
#define INDEX(arr,ind)  (lower_bound(all(arr),ind)-arr.begin())

typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<pii> vii;

const int N = 333;
const int MOD  = 1000000007;

/*Main code begins now */

int dis[N][N], used[N];

int main() {
    int n, k; 
    s(n); s(k);

    rep(i, n) rep(j, n) dis[i][j] = INF;
    rep(i, n) dis[i][i] = 0;

    rep(i, n - 1) {
        int u, v;
        s(u), s(v);
        --u; --v;
        dis[u][v] = dis[v][u] = 1;
    }

    rep(k, n) rep(i, n) rep(j, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    memset(used, 0, sizeof(used));
    rep(i, k) {
        int maxD = 0, maxC = 0, id = -1;
        rep(i, n) if(!used[i]) {
            int curMaxD = 0, curMaxC = 0;
            rep(j, n) if(!used[j]) {
                if(curMaxD < dis[i][j]) {
                    curMaxD = dis[i][j];
                    curMaxC = 1;
                } else if(curMaxD == dis[i][j]) ++curMaxC;
            }
            if(maxD < curMaxD) {
                maxD = curMaxD;
                maxC = curMaxC;
                id = i;
            } else if(maxD == curMaxD) {
                if(maxC < curMaxC) {
                    maxC = curMaxC;
                    id = i;
                }
            }
        }
        assert(id != -1);
        used[id] = true;
    }

    int ans = 0;
    rep(i, n) rep(j, n) if(!used[i] and !used[j]) ans = max(ans, dis[i][j]);
    printf("%d\n", ans);
    return 0;
}