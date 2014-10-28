#include <bits/stdc++.h>
using namespace std;

// uzumaki naruto
#define TRACE

#ifdef TRACE
#define dbgarr(a,n)   cerr << "["; for(int i = 0; i < n; ++i) cerr << a[i] << " ";cerr << "\b]\n";
#define dbg(args...)  {debug,args; cerr<<endl;}
#define pause()       cin.get();cin.get();

#else
#define dbgarr(a,n)
#define dbg(args...)
#define pause()
#endif

struct debugger {
    template<typename T> debugger& operator , (const T& v) {
        cerr<<v<<" "; return *this;
    }
} debug;

template <typename T1, typename T2>
inline ostream& operator << (ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
inline ostream &operator << (ostream & os,const vector<T>& v) {
    bool first = true; os << "[";
    for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if(!first) os << ", ";
        os << *ii; first = false;
    }
    return os << "]";
}

#define fr first
#define se second
#define pb push_back

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int NN = 112;
int wt[NN];
int dp[NN][NN];

int f(int st,int en,int cost){
    if (st == en) return 0;
    int &ans = dp[st][en];
    if (ans != -1) return ans;

    ans = numeric_limits<int> :: max();
    for(int i = st+1; i <= en; ++i){
        int sum = f(st,i-1,cost)+f(i,en,cost);

        int n1 = i-st, w1 = wt[i-1]-wt[st-1];
        int n2 = en-i+1 , w2 = wt[en]-wt[i-1];
        int add = n1*w1 + n2*w2 - cost;

        //dbg(st,en,i,"  ",n1,w1,n2,w2,add,sum);
        add = max(add,0);
        ans = min(ans,add+sum);
    }
    //dbg(st,en,cost," == ",ans);
    return ans;
}

bool valid(int cost,int allowed,int n){
    memset(dp,-1,sizeof(dp));
    int tym = f(1,n,cost);
    if (tym <= allowed) return true;
    return false;
}

void solve(){
    int n,allowed;
    cin >> n >> allowed;
    for(int i = 1; i <= n; ++i)
        cin >> wt[i], wt[i] += wt[i-1];

    int st = 0, en = 100000000;
    while(st < en){
        int mid = (st+en)/2;
        if (valid(mid,allowed,n)) en = mid;
        else st = mid+1;
    }
    cout << en << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
