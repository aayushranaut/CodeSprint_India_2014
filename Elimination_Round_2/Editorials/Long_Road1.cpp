#include<bits/stdc++.h>

using namespace std;

#define LL long long int
#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define vi vector<int>
#define F first
#define S second
#define MOD 1000000007
#define D double
#define LD long double

#define B 300
#define N 1000000

LL s[N], a[N], l[N], sm[N];

int main(){
	int n, i, j, e, c, d, si, q, type;
	LL INF = 10000000, x;
	INF *= INF;
	INF *= 10;
	sd(n);
	for(i = 0; i < n; i++){
		sd(j);
		l[i] = j;
	}
	for(i = 0; i < n; i++){
		sd(j);
		a[i] = j;
	}
	j = B - n % B;
	for(i = 0; i < j; i++){
		a[i + n] = 0;
		l[i + n] = INF;
	}
	n += j;
	for(si = 0; si < n; si += B){
		s[si] = a[si] - l[si];
		sm[si] = s[si];
		for(i = 1; i < B; i++){
			s[si + i] = s[si + i - 1] + a[si + i] - l[si + i];
			sm[si + i] = min(s[si + i], sm[si + i - 1]);
		}
	}
	sd(q);
	while(q--){
		sd(type);
		if(type == 1){
			sd(c); sd(d);
			c--;
			si = c / B;
			si *= B;
			a[c] = d;
			s[si] = a[si] - l[si];
			sm[si] = s[si];
			for(i = 1; i < B; i++){
				s[si + i] = a[si + i] - l[si + i] + s[si + i - 1];
				sm[si + i] = min(s[si + i], sm[si + i - 1]);
			}
		}
		else{
			sd(e);
			e--;
			x = 0;
			while(e % B != 0){
				x += a[e] - l[e];
				if(x < 0){
					break;
				}
				e++;
			}
			if(x >= 0){
				while(e < n){
					if(x + sm[e + B - 1] < 0){
						while(x + s[e] >= 0){
							e++;
						}
						break;
					}
					x += s[e + B - 1];
					e += B;
				}
			}
			printf("%d\n", e + 1);
		}
	}
    return 0;
}
