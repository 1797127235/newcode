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
void solve() {
    int n , m;
    cin >> n >> m;
    vector<PII> t(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i].fi >> t[i].se;
    }

    int ans = 0;

    for(int i = 1 ; i <= n ; i++)
    {
        int time = t[i].fi - t[i-1].fi;
        if(t[i].second == t[i-1].second)
        {
            if(time % 2 == 0)
            {
                ans = ans + time;
            }
            else
            {
                ans = ans + time - 1;
            }
        }
        else
        {
            if(time % 2)
            {
                ans = ans + time;
            }
            else
            {
                ans = ans + time - 1;
            }
        }
    }
    ans+= m - t[n].fi;
    cout<<ans<<endl;
     


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}