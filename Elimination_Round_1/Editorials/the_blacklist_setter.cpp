    #include< stdio.h >
    #include< iostream >
    #include< sstream >
    #include< string.h>
    #include< algorithm>
    #include< stdlib.h>
    #define maxn 105
    using namespace std;
    int dp[maxn][maxn],n,m;
    void precalc()  
    {
        memset(dp,1,sz(dp));
        for(int i = 0; i <=100;i++)
            dp[i][0] = 0;
        for(int i=0; i<=100;i++)
            dp[0][i] = 0;
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                if(i == j) {
                    dp[i][j] = 1;
                }else
                {
                    for(int k = 1;k<j;k++)
                        dp[i][j] = min(dp[i][k] + dp[i][j-k],dp[i][j]);
                    for(int k = 1;k<i;k++)
                        dp[i][j] = min(dp[k][j] + dp[i-k][j],dp[i][j]);
                }
                dp[j][i] = dp[i][j];
            }
        }
    }
    int main() {
        int tt;
        precalc();
        cin>>tt;
        while(tt--)
        {
            cin>>n>>m;
            cout<<dp[n][m]<<endl;
        }
        return 0;
    }