#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];
int main() {
    int n;
    long long k; 
    cin >> n >> k; 
    for(int i=0;i<n;i++)
        cin >> a[i]; 
    long long sm = 0; 
    int mx = 0; 
    for(int i=0;i<n;i++)
        mx = max(mx, a[i]);
    int cur = 0; 
    for(int i=0;i<n;i++){
        if(mx-a[i] >= cur){
            sm += mx-a[i]-cur; 
            cur = mx-a[i]; 
        }
        else {
            cur = mx-a[i]; 
        }
    }
   // cout << sm << endl; 
    if(sm <= k){
        cout << k-sm+1 << endl; 
    }
    else cout << 0 << endl; 
    return 0;
}
