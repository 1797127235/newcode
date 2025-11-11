//https://codeforces.com/problemset/problem/915/F

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
/*
    所有路径的最大值之和减去所有路径最小值之和
*/
class UnionFind {
public:
    UnionFind(int n) {
        p.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) p[i] = i;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) swap(rootX, rootY);
            int cnt = size[rootX] * size[rootY];
            p[rootY] = rootX;
            size[rootX] += size[rootY];
            return cnt;
        }
    }

    int getSize(int x) {
        return size[find(x)]; // 返回 x 所在集合的大小
    }

private:
    vector<int> p;
    vector<int> size;
};
void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    vvi g(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    auto check = [&](bool mx)
    {
        int total = 0;
        vi id(n);
        vi on(n + 1,0);
        iota(id.begin(), id.end(), 1);

        sort(id.begin(), id.end(), [&](int x, int y) {
            return mx ? a[x] < a[y] : a[x] > a[y];
        });

        UnionFind uf(n + 1);

        for(auto v : id)
        {
            on[v] = 1;
            for(auto u: g[v])
            {
                if(on[u])
                {
                    int cnt = uf.unite(v,u);
                    if(cnt) total += cnt * a[v];
                }
            }
        }

        return total;
    };

    int res = check(1) - check(0);
    print(res);

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}