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

//11倍数的性质
void solve() {
    int n;
    cin >> n;
    vi cnt(11);
    vector<PII> a(n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        reverse(s.begin(),s.end());
        int cur = 0;
        for(int j = 0; j < s.size(); j++)
        {
            if(j%2==0)
            {
                cur += (s[j]-'0');
            }
            else
            {
                cur -= (s[j]-'0');
            }
        }
        cur = (cur % 11 + 11) % 11;
        if(s.size()%2==0)
        {
            ans = ans + cnt[(11-cur)%11];
        }
        else
        {
            ans = ans + cnt[cur];
        }

        cnt[cur] ++;
        a[i] = {cur,s.size()%2};
    }

    cnt.assign(11,0);

    for(int j = n - 1; j >= 0; j--)
    {
        int cur = a[j].fi;
        int op = a[j].se;
        if(op == 0)
        {
            ans = ans + cnt[(11-cur)%11];
        }
        else
        {
            ans = ans + cnt[cur];
        }
        cnt[cur]++;
    }

    cout << ans << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}