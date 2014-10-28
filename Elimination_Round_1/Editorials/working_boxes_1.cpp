#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 500
#define LL long long int

LL dp[N][N], a[N];
LL sum[N];
int n, t;

inline bool pos(int c){
	int i, j, l;
	LL v;
	for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            dp[i][j] = 1123456789;
        }
    }
    for(i = 0; i < n; i++){
		dp[i][i] = 0;
    }
    for(l = 1; l < n; l++){
        for(i = 0; i + l < n; i++){
            for(j = i; j < i + l; j++){
            	v = max(dp[i][j] + (sum[i] - sum[j + 1]) * (j - i + 1) + dp[j + 1][i + l] + (sum[j + 1] - sum[i + l + 1]) * (i + l - j) - c, 0LL);
                dp[i][i + l] = min(dp[i][i + l], v);
            }
        }
    }
    return (dp[0][n - 1] <= t);
}

int main() {
    int i, j, l, r, m;
    cin>>n>>t;
    for(i = 0; i < n; i++){
        cin>>a[i];
    }
    sum[n] = 0;
    for(i = n - 1; i >= 0; i--){
		sum[i] = sum[i + 1] + a[i];
	}
    l = 0;
    r = 1123456789;
    while(l < r){
		m = (l + r) / 2;
		if(pos(m) == true){
			r = m;
		}
		else{
			l = m + 1;
		}
    }
    cout<<r<<endl;
    return 0;
}
