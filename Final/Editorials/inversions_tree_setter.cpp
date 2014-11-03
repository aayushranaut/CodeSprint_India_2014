#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int memsize = 60000000;
const int maxn = 100005;
const int parts = memsize / maxn;
const int part_sz = (3 * maxn) / parts;

int fwt[parts + 5][maxn + 5], a[3 * (maxn + 5)], b[3 * (maxn + 5)], lp, j, tin[maxn + 5], tout[maxn + 5], timer, timer2, tin_alt[maxn + 5], tout_alt[maxn + 5];
int fwt_small[maxn + 5], n, f[maxn + 5], t[maxn * 2 + 5], p[maxn * 2 + 5], m, x, y, i, ii, depth, c[maxn + 5], pref[3 * (maxn + 5)];
long long ret;

void addedge (int x, int y) {
    t[++ii] = y;
    p[ii] = f[x];
    f[x] = ii;
}

void change (int x, int y, int q) {
    a[x] = y, b[x] = q;
    int t = (x + part_sz - 1) / part_sz;
    for(int i = t; i <= lp; i = (i | (i - 1)) + 1) 
        for(j = y; j <= maxn; j = (j | (j - 1)) + 1)
            fwt[i][j] += q;
}

void dfs (int k) {
    tin[k] = ++timer; tin_alt[k] = ++timer2;
    ret += depth;
    for(int j = c[k]; j > 0; j = (j & (j - 1))) ret -= fwt_small[j];
    for(int j = c[k]; j <= maxn; j = (j | (j - 1)) + 1) ++fwt_small[j];
    change(tin[k], c[k], 1);
    change(2 * n + tin_alt[k], c[k], 1);
    int q = f[k];
    while (q > 0) {
        if (!tin[t[q]]) {
            ++depth;
            dfs(t[q]);
            --depth;
        }
        q = p[q];
    }
    tout[k] = ++timer; tout_alt[k] = timer2;
    change(tout[k], c[k], -1);
    for(int j = c[k]; j <= maxn; j = (j | (j - 1)) + 1) --fwt_small[j];
}

int query (int x, int y) {
    int ret = 0;
    for(int i = x / part_sz; i > 0; i = i & (i - 1))
        for(int j = y; j > 0; j = j & (j - 1)) ret += fwt[i][j];
    for(int i = (x / part_sz) * part_sz + 1; i <= x; i++) if (a[i] <= y) ret += b[i];
    return ret;
}

int above (int k, int lo, int hi) {
    return pref[tin[k]] - query(tin[k], lo - 1);
}

int below (int k, int lo, int hi) {
    return query(n + n + tout_alt[k], hi) - query(n + n + tin_alt[k] - 1, hi);
}


int main (int argc, char * const argv[]) {
//  freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    lp = (3 * n + part_sz - 1) / part_sz;
    for(i = 1; i <= n; i++) scanf("%d", &c[i]);
    for(i = 1; i < n; i++) {
        scanf("%d %d", &x, &y);

        addedge(x, y);
        addedge(y, x);
    }
    dfs(1);
    for(i = 1; i <= 3 * n; i++) pref[i] = pref[i - 1] + b[i];
    printf("%lld\n", ret);
    for(i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);

        if (c[x] < maxn) ret -= above(x, c[x] + 1, maxn) - 1;
        if (c[x] > 1) ret -= below(x, 1, c[x] - 1);
        change(tin[x], c[x], -1);
        change(tout[x], c[x], 1);
        change(n + n + tin_alt[x], c[x], -1);
        c[x] = y;
        change(tin[x], c[x], 1);
        change(tout[x], c[x], -1);
        change(n + n + tin_alt[x], c[x], 1);
        if (c[x] < maxn) ret += above(x, c[x] + 1, maxn) - 1;
        if (c[x] > 1) ret += below(x, 1, c[x] - 1);
        printf("%lld\n", ret);
    }
    return 0;
}