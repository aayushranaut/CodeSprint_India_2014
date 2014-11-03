#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))

#define MAX_N 1000010
int res[MAX_N];

int main()
{
   int n, k;
   scanf("%d", &n);    
   scanf("%d", &k);

   FOR(i, k)
   {
      int city;
      scanf("%d", &city);
      int sq = (int) sqrt(city);
      if(sq * sq == city)          
         res[city - 1]++;
   }
   FOR(i, n)
   {
      if(res[i] > 0)
      {
         printf("%d %d\n", i + 1, res[i]);
      }
   }
   return 0;   
}