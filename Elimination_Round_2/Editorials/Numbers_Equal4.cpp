#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b && n>=a)
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}
LL ar[100009];
LL temp[100009];
int n;
LL foo(LL h)
{
    for(int i=1; i<=n; i++)
        temp[i]=h-ar[i];
    LL ret=temp[1];
    for(int i=2; i<=n; i++)
        ret += max(0ll,temp[i]-temp[i-1]);
    return ret;
}
int main()
{
    LL maxi=-1;
    LL k;
    sd(n),sl(k);
    for(int i=1; i<=n; i++)
    {
        sl(ar[i]);
        maxi=max(maxi,ar[i]);
    }
    LL p=foo(maxi);
    if(p<=k)
        cout << k-p+1 << endl;
    else cout << 0 << endl;
    return 0;
}
