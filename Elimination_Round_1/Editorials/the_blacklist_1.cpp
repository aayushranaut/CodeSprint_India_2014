#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long int

#define N 100
#define T 3000

int val[N][N];
int tp[N];
LL dp[N][T];

int main() {
    LL INF = 1123456789, ans, v;
    INF *= INF;
    ans = INF;
    int n, k, i, j, l, mask;
    cin>>n>>k;
    for(j = 0; j < k; j++){
        for(i = 1; i <= n; i++){
            cin>>val[j][i];
        }
    }
    tp[0] = 1;
    for(i = 1; i < N; i++){
        tp[i] = tp[i - 1] + tp[i - 1];
    }
    for(i = 0; i <= n; i++){
        for(mask = 0; mask < tp[k]; mask++){
            dp[i][mask] = INF;
        }
    }
    dp[0][0] = 0;
    for(i = 0; i < n; i++){
        for(mask = 0; mask < tp[k]; mask++){
            for(j = 0; j < k; j++){
                if((mask & tp[j]) == 0){
                    v = dp[i][mask];
                    for(l = i + 1; l <= n; l++){
                        v += val[j][l];
                        dp[l][mask | tp[j]] = min(dp[l][mask | tp[j]], v);
                        if(l == n){
                            ans = min(ans, v);
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
