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
    //构造出n-k个环
    int n,k;
    cin >> n >> k;
    if(k >= n)
    {
        cout << -1 << endl;
        return;
    }
    vi t;
    int cur = n;
    for(int i = 1;i <= n-k-1;i++)
    {
        t.pb(2);
        cur -= 2;
        if(cur <= 1)
        {
            break;
        }
    }

    if(cur > 0)
    {
        t.pb(cur);
    }

    vi p;
    int st = 1;
    for(auto & cnt : t)
    {
        int ed = st + cnt - 1;
        for(int i = st+1;i <= ed;i++)
        {
            p.pb(i);
        }
        p.pb(st);
        st = ed + 1;
    }
    for(auto & x : p)
    {
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}