#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  if(k == 0) {
    printf("0\n");
  } else if(k == 1) {
    printf("%d\n", n/2);
  } else if(k == 2) {
    printf("%d\n", n==1? 0: n);
  } else if(k == 3) {
    printf("%lld\n", n==1? 0LL: n + (2LL*n-1));
  } else
    puts("-1");
}

int main(void) {
  int T;
  scanf("%d", &T);
  while(T--) solve();
  return 0;
}