//https://leetcode.cn/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[1]].push_back(e[0]); // 反向建图
        }

        vector<vector<int>> ans(n);
        vector<int> vis(n);
        function<void(int)> dfs = [&](int x) {
            vis[x] = true; // 避免重复访问
            for (int y : g[x]) {
                if (!vis[y]) {
                    dfs(y); // 只递归没有访问过的点
                }
            }
        };
        for (int i = 0; i < n; i++) {
            ranges::fill(vis, false);
            dfs(i); 
            vis[i] = false; // ans[i] 不含 i
            for (int j = 0; j < n; j++) {
                if (vis[j]) {
                    ans[i].push_back(j);
                }
            }
        }
        return ans;
    }
};
