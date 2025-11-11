//http://47.117.109.207/problem.php?id=1350

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

// void solve() {
//     int n;
//     int p1, p2;
//     cin >> n >> p1 >> p2;
//     vector<int> a(n + 1);
//     for (int i = 1; i <= n; ++i) cin >> a[i];

//     if (p1 == p2) {
//         cout << "Cat are already in fairytale kingdom\n";
//         return;
//     }

//     //dp[pos] 到达pos的最小距离
//     unordered_map<int, int> dp, ndp;

//     //pre[i][pos] = {prevpos, uesflag}
//     //0 不用第i张票 1:+a[i] -1:-a[i]
//     vector<unordered_map<int, pair<int,int>>> pre(n + 1);

//     dp[p1] = 0;  

//     for (int i = 1; i <= n; i++) {
//         ndp = dp; 


//         for (auto &[pos, dist] : dp) {
//             int npos = pos + a[i];
//             int ndist = dist + a[i];
//             if (!ndp.count(npos) || ndist < ndp[npos]) {
//                 ndp[npos] = ndist;
//                 pre[i][npos] = {pos, +1};
//             }

//             npos = pos - a[i];
//             ndist = dist + a[i];
//             if (!ndp.count(npos) || ndist < ndp[npos]) {
//                 ndp[npos] = ndist;
//                 pre[i][npos] = {pos, -1};
//             }

//         }

//         dp.swap(ndp);
//     }

//     if (!dp.count(p2)) {
//         cout << "Maybe it's good to be a waiter in a cat cafe\n";
//         return;
//     }

//     cout << "The cat finds its way to the fairytale kingdom\n";

//     vector<int> used;
//     int cur = p2;
//     for (int i = n; i >= 1; i--) {
//         auto it = pre[i].find(cur);
//         if (it == pre[i].end()) {
//             continue;
//         }
//         auto [prevpos, flag] = it->second;
//         if (flag != 0) {
//             used.pb(a[i]); 
//         }
//         cur = prevpos;
//     }

//     sort(used.begin(), used.end());
//     for (int i = 0; i < used.size(); ++i) {
//         cout << used[i] <<' ';
//     }
//     cout << endl;
// }


void solve()
{
    int n,p1,p2;
    cin >> n >> p1 >> p2;
    vi a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];

    if(p1 == p2)
    {
        cout << "Cat are already in fairytale kingdom\n";
        return;
    }
    vector<int> bestused;
    vector<int> used;
    int best = INF;
    auto dfs = [&](auto&& dfs,int u,int pos,int cnt)->void{
        if(cnt >= best) return ;

        if(u > n)
        {
            if(pos == p2 && cnt < best)
            {
                best = cnt;
                bestused = used;
            }
            return ;
        }

        dfs(dfs,u + 1,pos,cnt);

        used.push_back(a[u]);
        dfs(dfs,u + 1,pos + a[u],cnt + a[u]);
        used.pop_back();


        used.push_back(a[u]);
        dfs(dfs,u + 1,pos - a[u],cnt + a[u]);
        used.pop_back();
    };
    dfs(dfs,1,p1,0);

    if(best == INF)
    {
        cout << "Maybe it's good to be a waiter in a cat cafe\n";
        return ;
    }
    else
    {
        cout << "The cat finds its way to the fairytale kingdom\n";
        sort(bestused.begin(),bestused.end());
        for(auto& x : bestused)
        {
            cout << x << ' ';
        }
        cout << endl;
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