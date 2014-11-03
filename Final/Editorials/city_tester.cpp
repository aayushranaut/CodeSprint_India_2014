#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N, K;
    cin >> N >> K;
    assert(1 <= N && N <= (int)1e6);
    assert(1 <= K && K <= (int)1e6);

    vector <int> phi(N+1, 1);

    for(int i = 2; i <= N; i++) if(phi[i] == 1) {
        for(int j = i; j <= N; j+=i) {
            int x = j, m = 1;
            while(x % i == 0) {
                m++;
                x /= i;
            }
            phi[j] *= m;
        }
    }

    map <int, int> cnt;
    while(K--) {
        int x;
        cin >> x;
        assert(x >= 1 && x <= N);
        cnt[x]++;
    }

    for(auto it = (cnt).begin(); it != (cnt).end(); ++it) {
        int x = it->first, m = it->second;
        if(phi[x]%2 == 1)
            cout << x << " " << m << "\n";
    }

    return 0;
}