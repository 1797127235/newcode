//https://leetcode.cn/problems/power-grid-maintenance/description/
#include<bits/stdc++.h>
using namespace std;

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

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) swap(rootX, rootY);
            p[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    int getSize(int x) {
        return size[find(x)]; // 返回 x 所在集合的大小
    }

private:
    vector<int> p;
    vector<int> size;
};

class Solution1 {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        UnionFind uf(c + 1);
        for (const auto& conn : connections)
        {
            uf.unite(conn[0], conn[1]);
        }

        vector<set<int>> st(c + 1);

        for (int i = 1; i <= c; ++i)
        {
            st[uf.find(i)].insert(i);
        }

        vector<int> ans;
        vector<int> online(c + 1,1);

        for(auto &v: queries)
        {
            int op = v[0];
            int x = v[1];
            if(op == 1)
            {
                int rootX = uf.find(x);
                if(online[x] == 1)
                {
                    ans.push_back(x);
                }
                else if(st[rootX].size() > 0)
                {
                    ans.push_back(*st[rootX].begin());
                }
                else
                {
                    ans.push_back(-1);
                }
            }
            else
            {
                int rootX = uf.find(x);
                st[rootX].erase(x);
                online[x] = 0;
            }
        }

        return ans;
    }
};


class Solution2 {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> g(c + 1);
        for (auto& e : connections) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> belong(c + 1, -1);
        vector<priority_queue<int, vector<int>, greater<>>> heaps;
        priority_queue<int, vector<int>, greater<>> pq;

        auto dfs = [&](this auto&& dfs, int x) -> void {
            belong[x] = heaps.size(); // 记录节点 x 在哪个堆
            pq.push(x);
            for (int y : g[x]) {
                if (belong[y] < 0) {
                    dfs(y);
                }
            }
        };

        for (int i = 1; i <= c; i++) {
            if (belong[i] < 0) {
                dfs(i);
                heaps.emplace_back(move(pq));
            }
        }

        vector<int> ans;
        vector<int8_t> offline(c + 1);
        for (auto& q : queries) {
            int x = q[1];
            if (q[0] == 2) {
                offline[x] = true;
                continue;
            }
            if (!offline[x]) {
                ans.push_back(x);
                continue;
            }
            auto& h = heaps[belong[x]];
            // 懒删除：取堆顶的时候，如果离线，才删除
            while (!h.empty() && offline[h.top()]) {
                h.pop();
            }
            ans.push_back(h.empty() ? -1 : h.top());
        }
        return ans;
    }
};


class Solution3 {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> g(c + 1);
        for (auto& e : connections) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> belong(c + 1, -1);
        int cc = 0; // 连通块编号
        auto dfs = [&](this auto&& dfs, int x) -> void {
            belong[x] = cc; // 记录节点 x 在哪个连通块
            for (int y : g[x]) {
                if (belong[y] < 0) {
                    dfs(y);
                }
            }
        };

        for (int i = 1; i <= c; i++) {
            if (belong[i] < 0) {
                dfs(i);
                cc++;
            }
        }

        vector<int> offline_time(c + 1, INT_MAX);
        for (int i = queries.size() - 1; i >= 0; i--) {
            auto& q = queries[i];
            if (q[0] == 2) {
                offline_time[q[1]] = i; // 记录最早离线时间
            }
        }

        // 维护每个连通块的在线电站的最小编号
        vector<int> mn(cc, INT_MAX);
        for (int i = 1; i <= c; i++) {
            if (offline_time[i] == INT_MAX) { // 最终仍然在线
                int j = belong[i];
                mn[j] = min(mn[j], i);
            }
        }

        vector<int> ans;
        for (int i = queries.size() - 1; i >= 0; i--) {
            auto& q = queries[i];
            int x = q[1];
            int j = belong[x];
            if (q[0] == 2) {
                if (offline_time[x] == i) { // 变回在线
                    mn[j] = min(mn[j], x);
                }
            } else if (i < offline_time[x]) { // 已经在线（写 < 或者 <= 都可以）
                ans.push_back(x);
            } else if (mn[j] != INT_MAX) {
                ans.push_back(mn[j]);
            } else {
                ans.push_back(-1);
            }
        }
        ranges::reverse(ans);
        return ans;
    }
};


