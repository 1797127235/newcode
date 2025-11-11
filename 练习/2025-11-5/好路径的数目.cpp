//https://leetcode.cn/problems/number-of-good-paths/

#include <bits/stdc++.h>
#include <functional>
using namespace std;

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> idx(n);
        vector<int> fa(n);
        vector<int> sz(n,1);
        iota(idx.begin(), idx.end(), 0);
        iota(fa.begin(), fa.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return vals[a] < vals[b];
        });

        std::function<int(int)> find = [&](int x) -> int {
            if (x != fa[x])
                fa[x] = find(fa[x]);
            return fa[x];
        };
        /*
            从小到大遍历节点
        */
       int ans = n;

        for(auto x : idx)
        {
            int fx = find(x);
            for(auto &y : g[x])
            {
                int fy = find(y);

                if(vals[fx] > vals[fy]) continue;
                
                if(vals[fx] == vals[fy])
                {
                    ans += sz[fx] * sz[fy];
                    sz[fx] += sz[fy];
                }
                fa[fy] = fx;
            }
        }

        return ans;
    }
};