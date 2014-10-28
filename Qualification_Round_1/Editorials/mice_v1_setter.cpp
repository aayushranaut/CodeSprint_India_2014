#include <bits/stdc++.h>
typedef long long ll;
const ll N = (1<<17)+10;

int a[N];
int b[N];
int n;

int main()
{
    int test;

    scanf("%d", &test);
    for(int cas = 1; cas <= test; cas ++)
    {           
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);

        for(int i = 0; i < n; i ++)
            scanf("%d", &b[i]);

        sort(a, a+n);
        sort(b, b+n);

        int res = 0;
        for(int i = 0; i < n; i ++)
            res = max(res, abs(a[i]-b[i]));

        printf("%d\n", res);
    }

    return 0;
}