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
    int a,b;
    cin>>a>>b;
    if(a%2==0 && b%2)
    {

        cout<<-1<<endl;
        return;
    }
    int ans = 0;
    if(a%2==0 && b%2 ==0)
    {
        ans = a*b/2+2;
    }
    else if(a%2 && b%2)
    {
        ans = a*b+1;
    }
    else //奇 偶
    {
        int cnt =0 ;
        int t=b;
        while(t%2==0)
        {
            cnt++;
            t/=2;
        }
        if(cnt == 1)
        {
            ans = -1;
        }
        else
        {
            ans=a*b/2+2;
        }
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