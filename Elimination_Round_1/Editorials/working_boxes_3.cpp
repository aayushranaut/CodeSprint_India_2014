/*
 *Kartik Singal @ ka4tik
 */
#include<bits/stdc++.h>
using namespace std;
struct debugger{template<typename T> debugger& operator,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#define db(args...) do {cerr << #args << ": "; dbg,args; cerr << endl;} while(0)
#define s(n) scanf("%d",&n);
#define MAXN 111
#define ll long long
ll wt[MAXN];
ll get_wt(ll i,ll j)
{
    return wt[j]-(i-1>=0?wt[i-1]:0);
}
ll get_cost(ll i,ll j)
{
    return get_wt(i,j)*(j-i+1);
}
ll dp[MAXN][MAXN];
bool done[MAXN][MAXN];
ll rec(vector<ll> &v,ll left,ll right,ll t)
{
    //db(left,right);
    if(left==right)
        return 0;
    if(done[left][right])
        return dp[left][right];

    ll ans=LONG_MAX;
    for(ll k=left;k<right;k++)
    {
       ans=min(ans,max((ll)0,rec(v,left,k,t)+rec(v,k+1,right,t)+
               get_cost(left,k)+
               get_cost(k+1,right)-t));
    }
    done[left][right]=1;
    return dp[left][right]=ans;
}
ll check(vector<ll> &v,ll T,ll cost)
{
    ll n=v.size();
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            done[i][j]=0;
    ll t=rec(v,0,n-1,cost);
    return t<=T;
}
int main()
{
    //freopen("in","r",stdin);

    ll N;ll T;
    cin>>N>>T;
    vector<ll> v(N);
    for(ll i=0;i<N;i++)
        cin>>v[i];
    wt[0]=v[0];
    for(ll i=1;i<N;i++)
        wt[i]=wt[i-1]+v[i];
    ll lo=0;
    ll hi=LONG_MAX;
    while(lo<hi)
    {
        ll mid=lo+(hi-lo)/2;
        //db(lo,mid,hi);
        if(check(v,T,mid))
            hi=mid;
        else
            lo=mid+1;
    }
    cout<<lo<<endl;

    return 0;
}

