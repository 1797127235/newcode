//https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        vector<vector<int>> g(n);

        for(auto &e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<uint8_t> vis(n);
        long long cnt = 0;
        long long pre = 0;
        //dfs 求出每个集合有多少个点
        function<void(int u)> dfs = [&](int u) ->void
        {
            vis[u] = 1;
            cnt += 1;
            for(auto v : g[u])
            {
                if(vis[v]) continue;
                dfs(v);
            }
        };
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                cnt = 0;
                dfs(i);
                ans = ans + pre * cnt;
                pre += cnt;
            }
        }
        return ans;
    }
};