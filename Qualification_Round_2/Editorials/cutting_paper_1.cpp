#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
// Input macros
#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define ll long long
// Useful constants
#define INF (int)2e9
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd
// Useful container manipulation / traversal macros
#define all(a) a.begin(), a.end()
#define in(a,b) ( (b).find(a) != (b).end())
#define pb push_back
#define fill(a,v) memset(a, v, sizeof a)// fill originally
//#define sz(a) ((int)(a.size()))
#define mp make_pair

#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif

//#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
//#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define tr(container, it) for(aut(it,container.begin()); it != container.end(); it++)

#define llu long long unsigned
#define ld long
/*
int scan_d() {int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ld scan_ld() {int ip=getchar_unlocked(),flag=1;ld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ll scan_ll() {int ip=getchar_unlocked(),flag=1;ll ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
llu scan_llu() {int ip=getchar_unlocked();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}
//end of fast input
//fast output
//no line break
void print_d(int n) {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void print_ld(ld n) {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void print_ll(ll n) {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
void print_llu(llu n) {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
 */
#define DEBUG 1
#define debug(x) {if (DEBUG)cout <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; tr((x),it) cerr <<*it <<", "; cerr <<endl; }}
#define mod 1000000007

#define checkbit(n,b) ( (n >> b) & 1)
#define unsetbit(n,b) (n & (~(1 << b)))
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef vector<long long> vl;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long> > vpll;
typedef vector<string> vs;



int mem[109][109];

int dp(int i,int j)
{

	if( i == 0 || j == 0) return 0;

	int &ans = mem[i][j];

	if(ans > 0) return mem[i][j];

	ans=INF;

	int mini = min(i,j);



	for(int l=mini;l > 0;l--)
	{
		int ret = dp(i-l,j);
		ret += dp(l,j-l);
		int ret2 = dp(i,j-l);
		ret2 += dp(l,i-l);
		ret = min(ret,ret2);
		ret++;
		ans=  min(ans,ret);
	}
	return ans;
}

int main()
{

	int t;
	cin>>t;
	int n,m;
	while(t--)
	{
		fill(mem,-1);
		cin>>n>>m;
		cout<<dp(n,m)<<endl;
	}
}