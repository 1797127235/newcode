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

//滑动窗口
void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n+1);
    vi tot(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tot[a[i]]++;
    }


    for (int i = 1; i <= n; i++) {
        if (tot[i] % k != 0) { 
            cout << 0 << endl;
            return;
        }
    }


    vi lim(n+1, 0);
    for (int i = 1; i <= n; i++) lim[i] = tot[i] / k;


    vi cnt(n+1, 0);
    int ans = 0;
    int l = 1;
    for (int r = 1; r <= n; r++) {
        int x = a[r];
        cnt[x]++;


        while (cnt[x] > lim[x]) {
            cnt[a[l]]--;
            l++;
        }

        ans += (r - l + 1);
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