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

const int N = 200015;
const int MOD  = 1000000007;

#define l(x) (x << 1) + 1
#define r(x) (x << 1) + 2
#define mid(l, r) ((l + r) >> 1)

struct node 
{
    lli sum;
    lli minPrefix;
    bool wasNegative;

    inline void combine(const node & left, const node & right) {
        sum = left.sum + right.sum;
        minPrefix = min(left.minPrefix, left.sum + right.minPrefix);
        wasNegative = left.wasNegative or (left.sum + right.minPrefix < 0);
    }

    void print() {
        printf("Sum : %lld minPrefix : %lld wasNegative : %d\n", sum, minPrefix, wasNegative);
    }

} T[N << 2];

lli fuel[N], len[N], a[N];

struct segmentTree {
    int n;
    
    segmentTree(int m) : n(m) {
        build(0, 0, n - 1);
    }

    void build(int x, int l, int r) {
        if(l == r) {
            T[x].sum = a[l];
            T[x].minPrefix = min(0ll, a[l]);
            T[x].wasNegative = a[l] < 0;
            return;
        }
        int m = (l + r) >> 1;
        build(l(x), l, m);
        build(r(x), m + 1, r);
        T[x].combine(T[l(x)], T[r(x)]);
    }

    void update(int x, int l, int r, int pos, lli v) {
        if(l == pos and r == pos) {
            T[x].sum = v;
            T[x].minPrefix = min(0ll, v);
            T[x].wasNegative = v < 0;
            return;
        }
        int m = (l + r) >> 1;
        if(pos <= m) update(l(x), l, m, pos, v);
        else update(r(x), m + 1, r, pos, v);
        T[x].combine(T[l(x)], T[r(x)]);
    }

    node queryRange(int x, int l, int r, int ql, int qr) {
        if(l >= ql && r <= qr) return T[x];
        int m = (l + r) >> 1;
        if(qr <= m) return queryRange(l(x), l, m, ql, qr);
        if(ql > m) return queryRange(r(x), m + 1, r, ql, qr);
        node ret;
        ret.combine(queryRange(l(x), l, m, ql, qr), queryRange(r(x), m + 1, r, ql, qr));
        return ret;
    }

    void update(int pos, lli v) {
        update(0, 0, n - 1, pos, v);
    }

    node query(int ql, int qr) {
        return queryRange(0, 0, n - 1, ql, qr);
    }
};

int main() 
{
    int n; s(n);
    rep(i, n) sl(len[i]);
    rep(i, n) sl(fuel[i]);
    rep(i, n) a[i] = fuel[i] - len[i];

    segmentTree st(n);

    int Q; s(Q);
    rep(z, Q) {
        int type; s(type);
        if(type == 1) {
            int c, d;
            s(c), s(d);
            --c;
            fuel[c] = d;
            a[c] = fuel[c] - len[c];
            st.update(c, a[c]);
        } else {
            int e; s(e);
            --e;
            if(a[e] < 0) printf("%d\n", e + 1);
            else {
                int l = e, r = n - 1;
                while(l < r) {
                    int mid = (l + r + 1) >> 1;
                    node ret = st.query(e, mid);
                    if(ret.wasNegative) r = mid - 1;
                    else l = mid;
                }
                printf("%d\n", l + 2);
            }
        }
    }
    return 0;
}