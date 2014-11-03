#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define sd(x) scanf("%d",&x)
#define sfd(x) scanf("%d",&x)
#define pf printf

#define LL long long
#define ll long long
#define LD long double
#define ld long double
#define PB push_back
#define pb push_back
#define MP make_pair
#define mp make_pair
#define F first
#define S second

typedef pair<int,int> PII;
typedef vector<int> VI;

#define pii pair<int,int>
#define vi vector<int>
#define fr(i,n) for( int i=0; i<=n; i++)
#define frm(i,m,n) for(int i=m; i<=n; i++)

int n;
LL k;
int arr[200000];
void in()
{
    cin>>n>>k;
    int ma = 0;
    for(int i=0;i<n;i++){
        sd(arr[i]);
        ma = max(ma,arr[i]);
    }
    LL ans = 0,pres = 0;
    for(int i=0;i<n;i++){
        if(pres>= ma-arr[i]){
            pres = ma-arr[i];
        }
        else{
            ans += ma-arr[i]-pres;
            pres = ma-arr[i];
        }
    }
    //cout<<ans<<endl;
    if(ans<=k){
        cout<<(k-ans)+1<<endl;
    }
    else{
        cout<<0<<endl;
    }
}

void solve()
{

}

int main()
{
    int t = 1;
    //sd(t);
    while(t--){
        in();
        solve();
    }
    return 0;
}
