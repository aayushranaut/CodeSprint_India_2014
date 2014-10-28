/* Divanshu Garg */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <climits>
#include <cctype>
#include <cassert>
#include <complex>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FF(i,a,n) for(i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) ((a)>(b)?(a):(b))
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code begins here */

/* Input from file or online */

void input() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}

/* Input opener ends */

#define N 140000

ill a[N], b[N];
int n,m;

bool check(ill k) {
    int i = 0, j = 0;
    while ( i < n ) {
        while ( j < m && ABS(a[i]-b[j]) > k ) {
            j++;
        }
        if ( j == m ) return 0;
        i++; j++;
    }
    return true;
}


int main() {

   // input();

    int t; S(t);

    while ( t-- ) {
        S(n); S(m);

        F(i,0,n) Sl(a[i]);
        F(i,0,m) Sl(b[i]);

        sort(a,a+n);
        sort(b,b+m);

        ill ans = 100000000000LL, lo = 0, hi = 100000000000LL;
        while ( lo <= hi ) {
            ill mid = (lo+hi)/2;
            if ( check(mid) ) {
                ans = mid; hi = mid-1;
            } else lo = mid+1;
        }

        printf("%lld\n", ans);

    }


    return 0;
}