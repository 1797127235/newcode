#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define pb push_back
#define endl '\n' 
typedef pair<int, int> PII;
typedef long long ll;
#define rep(bg,ed, step) for (int i = bg; i <= ed; i += step)
#define per(bg,ed, step) for (int j = bg; j >= ed; j -= step)
const int INF = 1e18;
const int N = 1e5 + 10;
const int mod=1e9+7;

// Python-like print
template<typename... Args>
void print(Args... args) {
    ((cout << args << " "), ...);
    cout << endl;
}

void solve() {
    int n,t;
    cin >> n >> t;
    vector<PII> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i].fi ;
    }
    for(int i = 0; i < n; i++) {
        cin >> p[i].se;
    }
    sort(p.begin(),p.end());
    for(int i = 0; i < n; i++) {
        t-=p[i].fi;
        if(t < 0) {
            print(0);
            return;
        }
    }
    int ans = 0;
    for(int i = n - 1; i >=0; i--)
    {
        int x =p[i].fi*p[i].se;
        //cout << x << endl;
        if(t>=x)
        {
            t-=x;
            ans+=p[i].se;
        }
        else
        {
            ans = ans + (t+p[i].fi-1)/p[i].fi;
    
            t = 0;
            break;
        }
    }
    if(t>0) {
        print(-1);
    } else {
        print(ans);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}