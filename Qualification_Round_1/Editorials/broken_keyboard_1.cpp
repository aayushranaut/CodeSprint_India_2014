#include <bits/stdc++.h>
using namespace std;

bool tmp1[30],tmp2[30];
void solve(){
    memset(tmp1,false,sizeof(tmp1));
    memset(tmp2,false,sizeof(tmp2));
    string b,w;
    cin >> b >> w;
    
    for(int i = 0; i < (int)b.size(); ++i)
        tmp1[b[i]-'a'] = true;
    int ans = 0;
    for(int i = 0; i < (int)w.size(); ++i){
        if (tmp1[w[i]-'a'] and !tmp2[w[i]-'a'])
            ++ans,tmp2[w[i]-'a'] = true;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
