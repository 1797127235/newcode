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
    int n;
    cin >> n;
    vi a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;

    int cnt0 = 0;
    int cnt1 = 0;
    for(auto &x : a)
    {
        if(x == 0) cnt0++;
        else if(x == -1) cnt1++;
    }
    if(cnt1 % 2 == 0) ans =cnt0;
    else ans = cnt0 + 2;
    print(ans);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}