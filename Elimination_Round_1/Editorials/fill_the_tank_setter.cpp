#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXMOD = 1e6, MAXB = 50, INF = 2e9;
int minval[MAXMOD];
int bucket[MAXB], limit, B;
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqii;
void compute_vals() {
    fill(minval, minval + limit, INF);
    minval[0] = 0;
    pqii Q;
    register int x, val, i, fval, fx;
    for (Q.push(make_pair(0, 0)); !Q.empty(); Q.pop()) {
        pii ref = Q.top();
        x = ref.second, val = ref.first;
        if (val != minval[x]) continue;
        for (i = 0; i < B; ++i) {
            fval = val + bucket[i];
            fx = fval % limit;
            if (minval[fx] > fval) {
                minval[fx] = fval;
                Q.push(make_pair(fval, fx));
            }
        }
    }
}
int main() {

    register int Q, i, target;
    scanf("%d%d", &B, &Q);
    for (i = 0, limit = INF; i < B; ++i) {
        scanf("%d", bucket + i);
        if (limit > bucket[i]) limit = bucket[i];
    }
    compute_vals();
    while (Q--) {
        scanf("%d", &target);
        printf("%s\n", minval[target % limit] > target ? "no" : "yes");
    }
    return 0;
}