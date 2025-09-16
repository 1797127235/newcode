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
const int mod=998244353;
void solve() {
    int n;
    cin >> n;
    vi a(n+1),b(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    vvi dp(n+1,vi(2,0));

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= n; i++)
    {
        for(int cur = 0; cur <= 1; cur++)
        {
            for(int pre = 0; pre <= 1;pre++)
            {
                int curx =(cur == 0 ? a[i] : b[i]);
                int prex = (pre == 0 ? a[i-1] : b[i-1]);
                int cury = (cur == 0 ? b[i] : a[i]);
                int prey = (pre == 0 ? b[i-1] : a[i-1]);

                if(prex <= curx && prey <= cury)
                {
                    dp[i][cur] = (dp[i][cur] + dp[i-1][pre]) % mod;
                }
            }
        }
    }

    cout << (dp[n][0] + dp[n][1]) % mod << endl;
    

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}