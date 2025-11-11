//https://ac.nowcoder.com/acm/contest/121300/E
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
int dx[8] = {-2,-2,-1,1,2,2,1,-1};
int dy[8] = {-1,1,2,2,1,-1,-2,-2};

void solve() {
    int n,m,k,x1,y1,x2,y2;
    cin >> n >> m >>k >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2 && y1 == y2) {
        if (k % 2) {
            cout << "No\n";
            return;
        }
        
        int nx = -1, ny = -1;
        for (int dir = 0; dir < 8; ++dir) {
            int tx = x1 + dx[dir];
            int ty = y1 + dy[dir];
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m) {
                nx = tx; ny = ty;
                break;
            }
        }
        // 根本没有合法马步
        if (nx == -1) {
            cout << "No\n";
            return;
        }

        cout << "Yes\n";
        for (int i = 0; i < k / 2; ++i) {
            cout << nx << ' ' << ny << '\n';
            cout << x1 << ' ' << y1 << '\n';
        }
        return;
    }



    vector<vector<int>> dist(n+1,vector<int>(m+1,INF));
    vector<vector<uint8_t>> vis(n+1,vector<uint8_t>(m+1,0));
    vector<vector<PII>> parent(n+1,vector<PII>(m+1,{-1,-1}));
    dist[x1][y1] = 0;
    queue<PII> q;
    q.push({x1,y1});

    while(!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        for(int dir = 0; dir < 8; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(dist[nx][ny] > dist[x][y] + 1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x,y};
                q.push({nx,ny});
            }
        }
    }

    int d = dist[x2][y2];
    if (d == INF || d > k || ((k - d) & 1)) {
        cout << "No\n";
        return;
    }

    // 回溯完整路径（含起点和终点）
    vector<PII> path;
    int cx = x2, cy = y2;
    while (true) {
        path.push_back({cx, cy});
        if (cx == x1 && cy == y1) break;
        auto p = parent[cx][cy];
        cx = p.first;
        cy = p.second;
    }
    reverse(path.begin(), path.end());   // path[0] = 起点, path.back() = 终点

    // ans 保存真正的“每一步到达的格子”，不含起点
    vector<PII> ans;
    for (int i = 1; i < (int)path.size(); ++i) {
        ans.push_back(path[i]);
    }

    int extra = k - d;           
    if (extra > 0) {
        // 终点前一个点
        PII t = path[path.size() - 2];
        PII endp = path.back();
        // 在 t 和 endp 之间来回跳：end -> t -> end -> t -> ...
        while (extra > 0) {
            ans.push_back(t);
            ans.push_back(endp);
            extra -= 2;
        }
    }

    cout << "Yes\n";
    for (auto &p : ans) {
        cout << p.first << ' ' << p.second << '\n';
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