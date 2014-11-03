#include<iostream>
#include<limits.h>
#include<map>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<fstream>
using namespace std;//miller rabin primality 7 set for 64 bit int {2, 325, 9375, 28178, 450775, 9780504, 1795265022}
#define abs(x) ((x)>0?(x):-(x))
#define M 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define tkint(n) scanf("%d",&n)
#define tkchar(ch) scanf("%c",&ch)
#define tklong(n) scanf("%llu",&n)
#define  ms0(s) memset(s,0,sizeof s)
//vector<int> graph[2*100000+5];int visited[2*100000+5];
lld k;
lld d[100000+5];
int main()
{
	int n;
	cin>>n>>k;
	lld mx=0,ans=0;
	for(int i=1;i<=n;++i)cin>>d[i],mx=max(mx,d[i]);
	for(int i=1;i<=n;++i)d[i]=mx-d[i];

	for(int i=1;i<=n;++i)
	{
		ans+=max(d[i]-d[i-1],0LL);
	}
	cout<<max(k-ans+1,0LL);
}
