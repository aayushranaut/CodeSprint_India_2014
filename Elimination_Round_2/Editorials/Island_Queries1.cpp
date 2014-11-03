#include<bits/stdc++.h>

using namespace std;

#define LL long long int
#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define vi vector<int>
#define F first
#define S second
#define INF 2000000000
#define MOD 1000000007
#define D double
#define LD long double

#define N 512345

int p[N], pos[N];
int bit[N];

inline void update(int i, int v){
	while(i < N){
		bit[i] += v;
		i += (i & (-i));
	}
}

inline int query(int i){
	int ret = 0;
	while(i > 0){
		ret += bit[i];
		i -= (i & (-i));
	}
	return ret;
}

int main(){
	int n, i, x, y, type, q;
	sd(n); sd(q);
	for(i = 1; i <= n; i++){
		sd(p[i]);
		pos[p[i]] = i;
	}
	p[0] = n + 1;
	p[n + 1] = n + 1;
	for(i = 1; i <= n + 1; i++){
		update(max(p[i], p[i - 1]), 1);
	}
	while(q--){
		sd(type);
		if(type == 2){
			sd(x);
			printf("%d\n", x - query(x));
		}
		else{
			sd(x); sd(y);
			if(x == y){
				continue;
			}
			x = pos[x];
			y = pos[y];
			update(max(p[x], p[x - 1]), -1);
			update(max(p[x], p[x + 1]), -1);
			update(max(p[y], p[y - 1]), -1);
			update(max(p[y], p[y + 1]), -1);
			swap(p[x], p[y]);
			update(max(p[x], p[x - 1]), 1);
			update(max(p[x], p[x + 1]), 1);
			update(max(p[y], p[y - 1]), 1);
			update(max(p[y], p[y + 1]), 1);
			pos[p[x]] = x;
			pos[p[y]] = y;
		}
	}
    return 0;
}
