#include <bits/stdc++.h>
using namespace std;

const ll N = (1<<17)+10;

int a[N];
int b[N];
int n, m;

bool check(int tt)
{
    int i = 0;
    int j = 0;
    while(i < n && j < m)
    {
        if(abs(a[i]-b[j]) <= tt)
        {
            i ++;
            j ++;
        }
        else
        {
            j ++;
        }
    }

    if(i == n)
        return true;
    else
        return false;
}


int main()
{
    int test;

    scanf("%d", &test);
    for(int cas = 1; cas <= test; cas ++)
    {           
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);

        for(int i = 0; i < m; i ++)
            scanf("%d", &b[i]);

        sort(a, a+n);
        sort(b, b+m);

        int L = 0;
        int R = 210000000;
        int mid;
        while(L < R)
        {
            mid = (L+R)/2;
            if(check(mid) == true)
                R = mid;
            else
                L = mid+1;
        }

        printf("%d\n", L);
    }

    return 0;
}