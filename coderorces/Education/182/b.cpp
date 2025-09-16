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
    int n;
    cin >> n;
    vi p(n+1);
    vi vis(n+1,0);
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
        vis[p[i]] = 1;
    }
    //大的数字尽量放前面

    vi t;
    for(int i = n; i >= 1; i--)
    {
        if(!vis[i]) t.pb(i);
    }


    for(int i = 1,j=0; i <= n; i++)
    {
        if(p[i] == 0)
        {
            p[i] = t[j++];
        }
    }

    int l = 1;
    int r = n;
    while(l <= n && p[l] == l) l++;
    if(l == n + 1)
    {
        cout << 0 << endl;
        return ;
    }
    while(r>=1 && p[r] == r) r--;

    int  ans = r - l + 1;
    cout << ans << endl;


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}