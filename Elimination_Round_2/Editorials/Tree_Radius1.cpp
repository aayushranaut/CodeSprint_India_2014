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
#define INF 10000

int n,k,a,b;
int arr[400][400];
int vis[400];
int tem[400];
void in()
{
    for(int i=0;i<400;i++){
        for(int j=0;j<400;j++){
            arr[i][j] = INF;
        }
        arr[i][i] = 0;
        vis[i] =  0;
    }

    sd(n);sd(k);
    for(int i = 0;i<n-1;i++){
        sd(a);sd(b);
        a--;
        b--;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                arr[j][k] = min(arr[j][k],arr[j][i]+arr[i][k]);
            }
        }
    }
}

void solve()
{
    while(k--){
        int maxdi = 0;
        memset(tem,0,sizeof(tem));
        for(int i=0;i<n;i++){
            if(vis[i]==1)
                continue;
            for(int j=0;j<n;j++){
                if(vis[j]==1)
                    continue;
                maxdi = max(maxdi,arr[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==1)
                continue;
            for(int j=0;j<n;j++){
                if(vis[j]==1)
                    continue;
                if(arr[i][j] == maxdi){
                    tem[i]++;
                }
            }
        }
        int maxcnt = 0,u;
        for(int i=0;i<n;i++){
            if(tem[i]>maxcnt){
                maxcnt = tem[i];
                u = i;
            }
        }
        vis[u] = 1;
    }
    int fans = 0;
    for(int i=0;i<n;i++){
            if(vis[i]==1)
                continue;
            for(int j=0;j<n;j++){
                if(vis[j]==1)
                    continue;
                fans = max(fans,arr[i][j]);
            }
    }
    cout<<fans<<endl;
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
