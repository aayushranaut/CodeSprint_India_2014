#include<iostream>
#include<cassert>

using namespace std;
int MAX = (1 << 16);
int MASK = MAX - 1;
int table[(1 << 16)];
void set_tab()
{
    table[0] = 0;
    for(int i = 1; i < MAX; i++){
        table[i] = table[i >> 1] + (i & 1);
    }
}

int bit_count(int n)
{
    return table[(n >> 16) & MASK] + table[n & MASK];
}

int main()
{
    int n;
    cin >> n;
    set_tab();
    assert(1 <= n <= 1e5);
    int x = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        assert(1 <= temp <= 1e9);
        x ^= bit_count(temp);
    }
    if(0 == x)
        cout << "The other player :(" << endl;
    else
        cout << "Shaka :)" << endl;
    return 0;
}