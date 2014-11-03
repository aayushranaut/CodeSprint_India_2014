#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define LL long long int
#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define vi vector<int>
#define F first
#define S second
#define INF 2000000000
#define MOD 1000000007
#define D double
#define LD long double

#define N 1000000

int a[N];

int main() {
    int n, i;
    LL ans, m = 0;
    sd(n);
    for(i = 0; i < n; i++){
        sd(a[i]);
        m += a[i];
    }
    m /= n;
    ans = 0;
    for(i = 0; i < n; i++){
        if(a[i] < m){
            ans += (m - a[i]);
            a[i + 1] -= (m - a[i]);
        }
        else if(a[i] > m){
            ans += (a[i] - m);
            a[i + 1] += (a[i] - m);
        }
    }
    cout<<ans<<endl;
    return 0;
}
