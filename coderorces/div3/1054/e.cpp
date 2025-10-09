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
    vi a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vi c(n+1,0);
    for(auto &x : a) c[x]++;
    vi pc(n+1,-1);
    vi nc(n+1,0);
    while(k--)
    {
        int w = 0;
        while(c[w]) w++;
        nc.assign(n+1,0);
        for(int i = 0; i <= n; i++)
        {
            if(i < w && c[i] == 1) nc[i]+=c[i];
            else nc[w] =c[i];
        }
        if(pc == nc) break;
        pc = c;
        c = nc;
    }
    auto res = c;
    if(k%2==0) res = nc;
    else res = c;

    ll ans = 0;
    for(int i = 0; i <= n; i++) ans += (ll)i*res[i];
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}