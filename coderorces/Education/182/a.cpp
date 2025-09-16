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
    vi a(n + 1);
    vi s(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for(int l =1;l<=n;l++)
    {
        for(int r = l + 1 ; r<=n;r++)
        {
            int x1 = s[l];
            int x2 = s[r] -s[l];
            int x3 = s[n] - s[r];
            x1 %=3;
            x2 %=3;
            x3 %=3;
            if(x1 + x2 + x3 == 3 || (x1 == x2 && x2 == x3))
            {
                cout << l << " " << r << endl;
                return ;
            }
        }
    }

    cout<< 0 << " " << 0 << endl;



}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}