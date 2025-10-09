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
int n ;
string s;

int cal(char ch)
{
    vector<int> pos;
    for(int i = 0 ; i < s.size(); ++ i)
    {
        if(s[i] != ch) continue;
        pos.pb(i);
    }
    int sz = pos.size();

    for(int i = 0; i < sz; ++i)
    {
        pos[i] = pos[i] - i;
    }
    int ans = 0;
    int mid = pos[sz/2];
    for(int i = 0; i < sz; i++)
    {
        ans += abs(pos[i] - mid);
    }
    return ans;
}

void solve() {
    cin >> n;
    cin >> s;
    cout << min(cal('a'),cal('b')) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}