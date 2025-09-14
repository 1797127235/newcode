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
    int cnt0=0;
    int cnt1=0;
    int ans = 0;
    vi a;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x % 2)
        {
            cnt1++;
            a.pb(x);
        }
        else
        {
            cnt0++;
            ans+=x;
        }
    }

    if(cnt1==0)
    {
        cout<<0<<endl;
        return ;
    }

    sort(a.begin(),a.end());

    int i = a.size() -1 ;

    cnt1 = (cnt1 +1) /2 ;
    while(cnt1--)
    {
        ans+=a[i];
        i--;
    }

    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}