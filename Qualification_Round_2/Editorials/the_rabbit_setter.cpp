#include <bits/stdc++.h>
using namespace std;

void main(){
    int test;
    int x;
    cin >> test;
    while(test --)
    {
        cin >> x;
        for(int i = 1; true; i ++)
        {
            int low = i*(i+1)/2;
            int high = (i+1)*(i+2)/2 - 1;
            if(low <= x && x <= high)
            {
                cout << i << endl;
                break;
            }
        }
    }
}