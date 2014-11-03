// karanaggarwal
#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define CLR(a) a.clear()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define FORi(i,a,b) for(LET(i,a) ; i<b; i++)
#define repi(i,n) FORi(i,(__typeof(n))0,n)
#define FOR(i,a,b) for(i=a ; i<b; i++)
#define rep(i,n) FOR(i,0,n)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pi(n) printf("%d",n)
#define piw(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
#define sortv(a) sort(a.begin(),a.end())
#define DRT()  int t; cin>>t; while(t--)
#define DRI(n)  int n; cin>>n; 
#define DRII(n,m)  int n,m; cin>>n>>m; 
#define TRACE
using namespace std;

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);


#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;


int A[200002];
int P[200001];
int T[200001];
int BT[200001];
int N;




int query(int x)
{
    int ret = 0;
    while(x>0)
    {
        ret += BT[x];
        x &= (x-1);
    }
    return ret;
}

void update(int p)
{
    if(p<1 || p>N)return;
    int x = 0;
    if(A[p]<A[p+1] && A[p]<A[p-1])
        x = 1;
    else 
    if(A[p]>A[p+1] && A[p]>A[p-1])
        x = -1;
    p = A[p];
//    trace2(p,x);
    if(T[p]==x)return;
    int tmp = x;
    x =  x - T[p]; 
    T[p] = tmp;
    while(p<=N)
    {
        BT[p] += x;
        p += (p&(-p));
    }
}

int main()
{
    int q; 
    cin>>N; si(q);
    A[0] =10000000; A[N+1] = 10000000;
    for(int i=1; i<=N;i++)
    {
        si(A[i]);
        P[A[i]] = i;
    }
    
    for(int i=1; i<=N;i++)
        update(i);
//    for(int i=1; i<=N;i++) trace1(T[i]) ; cout<<endl;  
    while(q--)
    {
        int c,x,y; 
        si(c);
        if(c==2)
        {
            si(x);
            printf("%d\n",query(x));
        }
        else
        {
            si(x); si(y);
            int p1 = P[x]; int p2 = P[y];
            P[x] = p2; P[y] = p1;
            A[p1] = y; A[p2] = x;
            update(p1-1);update(p1); update(p1+1); update(p2-1); update(p2); update(p2+1);
        }
    }
    return 0;
}

