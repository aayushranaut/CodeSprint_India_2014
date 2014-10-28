#include<bits/stdc++.h>

using namespace std;

int mat[101][101];

void solve()
{
    mat[0][0] = 0;
    mat[0][1] = 0;
    mat[1][0] = 0;

    for(int i = 1; i <= 100; i++)
    {
        mat[i][1] = i;
        mat[1][i] = i;
    }
    for(int i = 2; i <= 100; i++)
    {
        for(int j = 2; j <= 100; j++)
        {
            int min = i * j, val;
            if(i == j)
            {
                min = 1;
            }
            else
            {
                for(int k = 1; k < i; k++)
                {
                    val = mat[k][j] + mat[i - k][j];
                    if(val < min)
                        min = val;
                }
                for(int k = 1; k < j; k++)
                {
                    val = mat[i][k] + mat[i][j - k];
                    if(val < min)
                        min = val;
                }
            }
            mat[i][j] = min;
        }
    }
}

int main()
{
    int n, x, y;
    cin >> n;
    solve();
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        cout << mat[x][y] << endl;
    }
    return 0;
}