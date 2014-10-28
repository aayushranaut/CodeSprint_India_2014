#include <bits/stdc++.h>
using namespace std;

void main(){
    int test;
    string s;
    int cnt[26];

    cin >> test;
    while(test --)
    {
        cin >> s;
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < s.size(); i ++)
            cnt[s[i]-'a'] ++;

        sort(cnt, cnt+26, greater<int>());

        int n = s.size();
        int res = INF;
        int nGroup, groupLen, now;
        for(int i = 1; i <= n; i ++)
        {
            if(n % i == 0)
            {
                nGroup = i;
                groupLen = n/i;
                if(nGroup > 26)
                    continue;

                now = 0;
                for(int j = 0; j < nGroup; j ++)
                    if( cnt[j] > groupLen )
                        now += cnt[j]-groupLen;

                for(int j = nGroup; j < 26; j ++)
                    now += cnt[j];

                res = min(res, now);
            }
        }
        cout << res << endl;
    }
}