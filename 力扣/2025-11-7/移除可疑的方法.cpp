//https://leetcode.cn/problems/remove-methods-from-project/


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

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);
        vector<uint8_t> vis(n);
        UnionFind uf(n);
        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
        }

        auto dfs = [&](auto &self, int u) -> void {
            vis[u] = 1;
            for (auto &v : g[u]) {
                uf.unite(u, v);
                if(!vis[v])
                self(self,v);
            }
        };
        vis[k] = 1;

        dfs(dfs,k);


        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            if(!vis[root])
            {
                for(auto &v : g[i])
                {
                    if(vis[uf.find(v)])
                    {
                        vis[uf.find(v)] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!vis[uf.find(i)]) {
                res.push_back(i);
            }
        }
        return res;

    }
};