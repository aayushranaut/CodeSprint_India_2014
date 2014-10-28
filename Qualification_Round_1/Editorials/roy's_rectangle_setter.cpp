#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while( test-- ){
        int x,y;
        int x1,y1;
        int x2,y2;
        cin >> x >> y;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        int ans = 2000000001;
        ans = min( ans , abs(x-x1) );
        ans = min( ans , abs(x-x2) );
        ans = min( ans , abs(y-y1) );
        ans = min( ans , abs(y-y2) );
        cout << ans << endl;
    }
    return 0;
}