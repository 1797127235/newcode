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
    cin>>n;
    vi b(n+1);
    for(int i=1;i<=n;i++) cin>>b[i];
    map<int,vector<int>> pos;

    for(int i=1;i<=n;i++){
        pos[b[i]].pb(i);
    }

    vi a(n+1,0);

    int cur = 1;

    for(int k = 1;k <= n; ++k)
    {
        if(pos.find(k) == pos.end()) continue;

        int cnt = pos[k].size();

        if(cnt % k)  //交的下标数必须是k的倍数
        {
            cout<< -1 << endl;
            return ;
        }

        for(int i = 0; i <cnt ;i+= k)
        {
            for(int j = 0 ; j < k; ++j)
            {
                a[pos[k][i+j]] = cur;
            }
            cur++;
        }
    }

    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}