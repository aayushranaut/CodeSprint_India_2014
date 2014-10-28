#include <cstdio>
#include <cassert>
using namespace std;
const int SIZE = 1 << 16, MASK = (1 << 16) - 1;
int tab[SIZE];

inline void make_tab() {
    for (register int i = 1; i < SIZE; ++i) {
        tab[i] = tab[i >> 1] + (i & 1);
    }
}

inline int bcount(int n) {
    return tab[n & MASK] + tab[(n >> 16) & MASK];
}
const int TEST = 0;
int main() {
    /*
    char inputstr[50];
    char outputstr[50];
    sprintf(inputstr, "tests/input/input%02d.txt", TEST);
    sprintf(outputstr, "tests/output/output%02d.txt", TEST);
    freopen(inputstr, "r", stdin);
    freopen(outputstr, "w", stdout);
    */

    make_tab();
    register int i, N, rx, x;
    for (scanf("%d", &N), i = rx = 0; i < N; ++i) {
        scanf("%d", &x);
        assert(x >= 0);
        x = bcount(x);
        rx ^= x;
    }
    printf("%s\n", rx == 0 ? "The other player :(" : "Shaka :)");
    return 0;
}