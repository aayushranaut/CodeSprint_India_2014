//#define DEBUG
#include<bits/stdc++.h>
#define X first
#define Y second
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define ALL(x) x.begin(),x.end()
#define INIT(x,y) memset(x,y,sizeof x)
#define PQ priority_queue
#define IT iterator
#define INF 1e9
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;

int MOD=1000000007;
ll fac[100005];
inline int bin_pow(int a,int x)
{
    if(x==0)return 1;
    ll res=bin_pow(a,x/2);
    res*=res;
    res%=MOD;
    if(x%2)res*=a;
    res%=MOD;
    return res;
}
inline int inverse(int x)
{
    return bin_pow(x,MOD-2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i,res;
    ll a;
    fac[0]=1;
    for(i=1;i<=100000;i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=MOD;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        res=0;
        for(i=0;i<n;i++)
        {
            cin>>a;
            a*=i%2?-1:1;
            a%=MOD;
            a*=fac[n-1];
            a%=MOD;
            a*=inverse(fac[n-1-i]);
            a%=MOD;
            a*=inverse(fac[i]);
            a%=MOD;
            res+=a;
            res%=MOD;
        }
        cout<<(res+MOD)%MOD<<"\n";
    }
}
