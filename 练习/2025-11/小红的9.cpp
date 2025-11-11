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
    vector<vector<int>> g(n + 1);
    
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> down(n + 1, vector<int>(10,0));
    vector<vector<int>> up(n + 1, vector<int>(10,0));

    auto dfs1 = [&](auto&& dfs1,int u,int fa)->void{
        down[u][0] = 1;
        for(auto &v : g[u])
        {
            if(v == fa) continue;

            dfs1(dfs1,v,u);
            for(int d = 1; d <= 9; d++)
            {
                down[u][d] += down[v][d - 1];
            }
        }
    };
    dfs1(dfs1,1,-1);
    vector<int> ans(n + 1,0);


    auto dfs2 =[&](auto& dfs2,int u,int fa)->void{
        vector<int> total(10,0);
        for(int d = 0; d <=9;d++)
        {
            total[d] = down[u][d] + up[u][d];
        }

        for(auto &v : g[u])
        {
            if(v == fa) continue;

            for(int d = 1; d <=9; d++)
            {
                up[v][d] = down[u][d - 1] + up[u][d - 1];
                
                if(d >=2)
                {
                    up[v][d] -= down[v][d - 2];
                }
            }
            dfs2(dfs2,v,u);
        }
    };

    dfs2(dfs2,1,-1);

    for(int i = 1; i <= n; i++)
    {
        ans[i] = down[i][9] + up[i][9];
        cout << ans[i] << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
