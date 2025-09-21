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
    string x;
    cin >> x;
    if(x.size() == 1)
    {
        print(x);
        return ;
    }
    x = '#' + x;

    int ans = 0;
    vi s(x.size() + 1);
    
    for(int i = 1; i < x.size(); i++)
    {
        s[i] = s[i-1] + (x[i] - '0');
    }

    for(int i = 1;i < x.size() ;i++)
    {
        ans += (x[i] -'0');
        for(int j = i -1 ;j >= 1; j--)
        {
            int t = s[i] - s[j-1];
            while(t)
            {
                ans = ans + t%10;
                t = t / 10;
            }
        }
    }
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