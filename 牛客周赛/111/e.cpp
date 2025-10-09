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
const int mod = 1e9 + 7;

// Python-like print
template<typename... Args>
void print(Args... args) {
    ((cout << args << " " ), ...);
    cout << '\n';
}

void solve() {
    int n,k;
    cin >> n >> k;
    int mn = 3*n - 1;
    int mx = (n*n+3*n) / 2;
    if(k < mn || k > mx)
    {
        cout << -1 << endl;
        return ;
    }
    vi ans;
    vi vis(n + 1,0);
    vis[n] = 1;
    vis[n-1] = 1;
    ans.pb(n);
    k -= mn;

    vi t;
    for(int i = n -2; i >=1; i--)
    {
        if(k >= i)
        {
            k-=i;
            t.pb(i);
            vis[i] = 1;
        }
    }
    if(k)
    {
        cout << -1 << endl;
        return ;
    }

    for(int i = 1; i <=n;i++)
    {
        if(!vis[i]) ans.pb(i);
    }
    
    if(n - 1)
    ans.pb(n-1);

    for(auto& x : t)
    {
        ans.pb(x);
    }

    for(auto &x : ans)
    {
        cout << x << ' ';
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