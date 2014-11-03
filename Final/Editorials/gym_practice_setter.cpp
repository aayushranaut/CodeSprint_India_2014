#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

#define left Left
#define right Right
#define maxn 100005
#define max_waiting 500
#define part_sz 500

struct item {
    long long a, b;
} st[maxn];

vector<int> v[maxn];
vector<pair<long long, long long> > waiting[1000];
int sp, parts, left[maxn], right[maxn], left_idx[maxn], right_idx[maxn], in_wait, i, cn, n, m, best_second;
int L[maxn], R[maxn], D[maxn], C[maxn], S[maxn], idx;
long long best_line[maxn], sum_ax[maxn], sum_b[maxn], sum_special[maxn], carry, j, dp[maxn], start_term[maxn], step[maxn];
bool exist[maxn];

bool ccw (item a, item b, item c) {
    return (long double)(b.b - a.b) * (long double)(b.a - c.a) >= (long double)(c.b - b.b) * (long double)(a.a - b.a);
}

void add_to_stack (long long x, long long y) {
    ++sp;
    st[sp].a = x, st[sp].b = y;
    while (sp >= 3 && ccw(st[sp - 2], st[sp - 1], st[sp])) {
        swap(st[sp - 1], st[sp]);
        --sp;
    }
}

void add_line (int l, int r, long long a, long long b) {
    for(int i = 1; i <= parts; i++) if (l <= left[i] && right[i] <= r) {
        waiting[i].push_back(make_pair(a - l * 1LL * b, b));
    } else {
        if (right[i] < l) continue;
        if (left[i] > r) continue;
        long long ax = 1LL * a - l * 1LL * b;
        for(int j = left_idx[i]; j <= right_idx[i]; j++) if (l <= j && j <= r) {
            if (!exist[j]) {
                best_line[j] = ax + j * 1LL * b;
                exist[j] = true;
            } else best_line[j] = max(best_line[j], ax + j * 1LL * b);
        }
    }
    ++in_wait;
    if (in_wait == max_waiting) {
        for(int i = 1; i <= parts; i++) if (waiting[i].size() != 0) {
            sort(waiting[i].begin(), waiting[i].end());
            reverse(waiting[i].begin(), waiting[i].end());
            sp = 0;
            best_second = -1000000000 * 2;
            for(int j = 0; j < waiting[i].size(); j++)
                if (j == 0 || waiting[i][j].second > best_second) {
                    add_to_stack(waiting[i][j].second, waiting[i][j].first);
                    best_second = waiting[i][j].second;
                }
            int ql = 1;
            for(int j = left_idx[i]; j <= right_idx[i]; j++) {
                long long opt = st[ql].b + st[ql].a * j;
                for(int k = ql + 1; k <= sp; k++) if (opt < st[k].a * j + st[k].b) {
                    opt = st[k].a * j + st[k].b;
                    ql = k;
                } else break;
                if (!exist[j]) best_line[j] = opt; else best_line[j] = max(best_line[j], opt);
                exist[j] = true;
            }
            waiting[i].clear();
        }
        in_wait = 0;
    }   
}

void build_decomposition () {
    for(i = 1; i <= n; i++) {
        if (i % part_sz == 1) {
            ++parts;
            left[parts] = i;
            left_idx[parts] = i;
        }
        if (i % part_sz == 0 || i == n) {
            right[parts] = i;
            right_idx[parts] = i;
        }
    }   
}

long long get_bestline (int k) {
    for(int i = 1; i <= parts; i++) if (left[i] <= k && k <= right[i] && waiting[i].size() != 0) {
        long long opt = waiting[i][0].first + waiting[i][0].second * 1LL * k;
        for(int j = 1; j < waiting[i].size(); j++) opt = max(opt, waiting[i][j].first + waiting[i][j].second * 1LL * k);
        if (!exist[k]) return carry + opt; else return carry + max(opt, best_line[k]);
    }
    if (!exist[k]) return 0;
    return carry + best_line[k];
}

int main (int argc, char * const argv[]) {
//  freopen("17.in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    assert(1 <= n && n <= 100000);
    assert(1 <= m && m <= 100000);
    for(i = 1; i <= m; i++) {
        scanf("%d %d %d %d %d", &L[i], &R[i], &D[i], &C[i], &S[i]);
        assert(1 <= L[i] && L[i] <= R[i] && R[i] <= D[i] && D[i] <= n);
        assert(1 <= C[i] && C[i] <= 10000);
        assert(1 <= S[i] && S[i] <= 10000);
        start_term[i] = S[i] + C[i] * 1LL * (R[i] - L[i] + 1);
        step[i] = C[i];
        v[R[i]].push_back(i);
    }
    build_decomposition();
    dp[0] = 0;
    for(i = 1; i <= n; i++) {
        for(j = 0; j < v[i].size(); j++) {
            idx = v[i][j];
            add_line(R[idx], D[idx], start_term[idx] + dp[L[idx] - 1], step[idx]);
        }
        dp[i] = max(dp[i - 1], get_bestline(i));
    }
    printf("%lld\n", dp[n]);
    assert(0 <= dp[n] && dp[n] <= 2000000000);
    return 0;
}