#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

#define inp_s     ios_base::sync_with_stdio(false)
#define VI        vector<int>
#define VS        vector<string>
#define VLL       vector<LL>
#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     c.size()
#define clr(c)    c.clear()
#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define DRT()     int t;cin>>t;while(t--)
#define gcd(a,b)  __gcd(a,b)

int main()
{
      inp_s;
        DRT()
        {
            int n;
            cin>>n;
            int arr[n];
            FOR(i,0,n) cin>>arr[i];
            double avg = 0.0;
            FOR(i,0,n) avg += arr[i];
            avg/=n;
            int cnt = 0;
            FOR(i,0,n) if(arr[i]>avg) cnt++;
                cout<<cnt<<endl;
    }
      return 0;
}