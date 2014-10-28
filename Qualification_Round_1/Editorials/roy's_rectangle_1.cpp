#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        long long x,y,x1,y1,x2,y2;
        scanf("%lld%lld%lld%lld%lld%lld",&x,&y,&x1,&y1,&x2,&y2);
        long long ans = min(min(x-x1,x2-x),min(y-y1,y2-y));
        printf("%lld\n",ans);
    }
    return 0;
}
