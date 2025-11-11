//https://leetcode.cn/problems/sum-of-distances-in-tree/description/

#include <bits/stdc++.h>
using namespace std;

/*
    换根DP模板
*/
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> sz(n,1);
        vector<int> ans(n,0);
        auto dfs = [&](this auto&&dfs,int u,int fa,int deepth)->void{

            ans[0] += deepth;
            for(auto &v : g[u])
            {
                if(v == fa) continue;

                dfs(v,u,deepth + 1);
                sz[u] += sz[v];
            }
        };
        dfs(0,-1,0);

        auto dfs2 = [&](this auto&&dfs2,int u,int fa)->void{
            for(auto &v : g[u])
            {
                if(v == fa) continue;

                ans[v] = ans[u] + n - 2 * sz[v];
                dfs2(v,u);
            }
        };

        dfs2(0,-1);
        
        return ans;
    }
};