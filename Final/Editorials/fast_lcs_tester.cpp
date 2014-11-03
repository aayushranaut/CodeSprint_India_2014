#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define MAX 100001

int n, m;
int a[MAX], b[MAX];

map<int, int> mp;
vector<int> all;

vector<int> p[MAX * 2];

int dp[2][501];
bool sign[MAX][501];

int main() {
    // freopen("test.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    for (int i = 0; i < n; i++) all.push_back(a[i]);
    for (int i = 0; i < m; i++) all.push_back(b[i]);

    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());

    for (int i = 0; i < all.size(); i++) mp[all[i]] = i;

    for (int i = 0; i < m; i++) p[mp[b[i]]].push_back(i);

    if (m > 500) m = 500;
    for (int j = 0; j <= m; j++) dp[0][j] = 1 << 25;
    dp[0][0] = -1;


    vector<int> res;

    for (int i = 1; i <= n; i++) {
        int num = mp[a[i - 1]];
        dp[i & 1][0] = -1;

        for (int j = 1; j <= m; j++) {
            dp[i & 1][j] = dp[(i & 1) ^ 1][j];
            sign[i][j] = false;
            if (p[num].size() > 0 && p[num].back() > dp[(i & 1) ^ 1][j - 1]) {
                int pos = *upper_bound(p[num].begin(), p[num].end(), dp[(i & 1) ^ 1][j - 1]);
                if (pos < dp[i & 1][j]) {
                    dp[i & 1][j] = pos;
                    sign[i][j] = true;
                }
            }
        }
    }

    int k;
    for (k = m; k >= 1; k--)
        if (dp[n & 1][k] < (1 << 25)) break;

    int i = n;
    int j = k;
    while (j > 0) {
        if (sign[i][j]) {
            i--;
            j--;
            res.push_back(a[i]);
        }
        else {
            i--;
        }
    }

    for (int i = (int)res.size() - 1; i >= 1; i--) printf("%d ", res[i]);
    if (res.size() > 0) printf("%d\n", res[0]);

    return 0;
}