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
    int n;
    cin >> n;
    vi p(n + 1);
     map<int,int> pos;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    string x;
    cin >> x;
    x = ' ' + x;
    if(x[1] == '1' || x.back() == '1')
    {
        cout << -1 << endl;
        return;
    }

    // 对于每个x[i] == '1',都能在左右两边找到比他小和比它大的数

    int l = INF;
    int r = -INF;

    for(int i = 1; i <= n; ++i)
    {
        if(x[i] == '1')
        {
            l = min(l,i);
            r = max(r,i);
        }
    }

    int lmin = INF;
    int rmax = -INF;
    for(int i = l; i <= r; ++i)
    {
        if(x[i] == '1')
        {
            lmin = min(lmin, p[i]);
            rmax = max(rmax, p[i]);
        }
    }

    int xx = INF;
    int yy = -INF;
    for(int i = l - 1; i >= 1; --i)
    {
        xx = min(xx,p[i]);
    }

    for(int i = r + 1; i <= n; ++i)
    {
        yy = max(yy,p[i]);
    }

    if(xx >= lmin || yy <= rmax)
    {
        cout << -1 << endl;
        return ;
    }

    int ansl = 0;
    int ansr = 0;

    for(int i = 1; i <= n; ++i)
    {
        if(p[i] == xx)
        {
            ansl = i;
        }
        if(p[i] == yy)
        {
            ansr = i;
        }
    }

    cout << ansl << " " << ansr << endl;
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}