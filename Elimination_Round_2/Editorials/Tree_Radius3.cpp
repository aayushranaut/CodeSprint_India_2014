#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)

typedef long long int LL;

int target;
int source;
int dist;
bool found;
int cnt = 0;
vector<int > g[333];
int D[333][333];
int n,K;

int dfs(int c, int p, int d) {

	if(c == target) {
		dist = d;
		found = true;
	}
	int res = 1;
	rep(i,0,g[c].size()) {
		int u = g[c][i];
		if(u != p) {
			res += dfs(u, c, d+1);
		}
	}
	return res;

}


void dfs2(int c, int p, int d) {

	if(D[c][target] > dist) cnt++;
	else if(D[c][source] > dist) cnt++;
	rep(i,0,g[c].size()) {
		int u = g[c][i];
		if(u != p) {
			dfs2(u, c, d+1);
		}
	}

}


void dfs3(int c, int p, int d, int x) {
	D[x][c] = d;

	rep(i,0,g[c].size()) {
		int u = g[c][i];
		if(u != p) {
			dfs3(u, c, d+1, x);
		}
	}
}

void pre() {

	rep(i,0,n) {
		dfs3(i, -1, 0, i);
	}

}

int main() {
	S(n);S(K);


	rep(i,0,n-1) {
		int u,v;
		S(u);
		S(v);
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	pre();

	int ans = -1;
	rep(i,0,n) rep(j,i+1,n) {

		target = j;
		source = i;
		dist = -1;
		int idx = -1;
		int sz = 0;
		rep(k,0,g[i].size()) {
			found = false;
			int x = dfs(g[i][k], i, 1);
			if(found) {
				idx = k;
			} else {
				sz += x;
			}
		}
		// printf("%d %d %d %d\n",i,j,dist,sz);
		if(sz <= K && idx != -1) {
			cnt = 0;
			dfs2(g[i][idx], i, 1);
			if(sz + cnt <= K) {
				if(ans == -1 || dist < ans)
					ans = dist;
			}
		}

	}
	P(ans);

	return 0;
}