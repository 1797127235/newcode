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
    vi a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());

    if(n == 2)
    {
        print(0);
        return ;
    }

    int mid =(n + 1) / 2;
    int tmid = mid;
    //删除最大或者最小的

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = ans + abs(a[i] - a[mid]);
    }

    //删除最大的
    if(n % 2)
    {
        mid -- ;
        int t = 0;
        for(int i = 1; i < n; i++)
        {
            t = t + abs(a[i] - a[mid]);
        }
        ans = min(ans, t);
    }
    else
    {
        int t = 0;
        for(int i = 1; i < n; i++)
        {
            t = t + abs(a[i] - a[mid]);
        } 
        ans = min(ans, t);
    }

    mid = tmid;
    //删除最小的
    if(n % 2)
    {
        int t = 0;
        for(int i = 2; i <= n; i++)
        {
            t = t + abs(a[i] - a[mid]);
        }
        ans = min(ans, t);
    }
    else
    {
        mid++;
        int t = 0;
        for(int i = 2; i <= n; i++)
        {
            t = t + abs(a[i] - a[mid]);
        }
        ans = min(ans, t);
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