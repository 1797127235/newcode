#include <bits/stdc++.h>
using namespace std;
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

ll cost(const vector<int>& pos) {
    int m = (int)pos.size();
    if (m <= 1) return 0;
    vector<ll> arr(m);
    for (int i = 0; i < m; ++i) arr[i] = (ll)pos[i] - i; 
    nth_element(arr.begin(), arr.begin() + m/2, arr.end());
    ll med = arr[m/2];
    ll res = 0;
    for (ll x : arr) res += llabs(x - med);
    return res;
}

void solve() {
    int n;
     cin >> n;
    string s;
     cin >> s;
    vector<int> posa, posb;
    posa.reserve(n);
     posb.reserve(n);
    for (int i = 0; i < n; ++i)
        (s[i] == 'a' ? posa : posb).pb(i);

    ll ans = min(cost(posa), cost(posb));
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}