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
    int n,k;
    cin >> n >> k;
    vi a(n + 1);
    vi b(k);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> b[i];
    }

    sort(a.begin() + 1, a.end(), greater<int>());

    sort(b.begin() , b.end());
    int i = 1;
    int  ans = 0;
    for(auto x : b)
    {
        if(x==1)
        {
            i++;
        }
        else
        {
            x -=1;
            while(i<=n&&x--)
            {
                ans += a[i];
                i++;
            }
            i++;
        }

        if(i > n) break;
    }

    for(int j = i ; j <= n; j++)
    {
        ans += a[j];
    }


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