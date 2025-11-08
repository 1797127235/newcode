//https://leetcode.cn/problems/all-paths-from-source-to-target/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n = g.size();

        vector<vector<int>> ans;
        vector<int> path;

        auto dfs = [&](this auto&& dfs, int x) -> void {
            path.push_back(x);
            if(x == n - 1)
            {
                ans.push_back(path);
                return;
            }

            for(auto &v : g[x])
            {
                dfs(v);
                path.pop_back();
            }
        };


        dfs(0);

        return ans;
    }
};