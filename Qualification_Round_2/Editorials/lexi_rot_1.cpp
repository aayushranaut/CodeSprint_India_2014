#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test ;
    string s;
    cin >>test;
    for(int z =1;z <= test;z++)
    {
        cin>>s;
        string maxi =s;
        s+=s;
        int n = s.size()/2;
        for(int i =1; i < n;i++)
        {
            string p = s.substr(i,n);
            maxi = max(maxi,p);
        }
        cout<<maxi<<endl;
    }
}
