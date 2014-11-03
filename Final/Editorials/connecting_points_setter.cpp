#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define INF 1000000007
#define y1 agaga
#define ll long long
#define ull unsigned long long

vector<int> V;
int n,k;

int f(int n, int k)
{
    if (n == 1 || k == 0) return 0;
    if (k == 1) return n / 2;
    if (k == 2) return n;
    if (k >= 4) return -1;
    return -2;       
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
        {

    cin >> n >> k;

    if (f(n,k)!=-2)
    {
        cout << f(n,k) << endl;
        continue;
    }


        cout << (ll)(n)*3-1<< endl;

    }


    return 0;
}