//https://leetcode.cn/problems/number-of-provinces/description/

#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> g(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);

        int ans = 0;

        auto dfs = [&](this auto&& dfs, int x) -> void {
            vis[x] = 1;
            for (int y : g[x]) {
                if (!vis[y]) {
                    dfs(y);
                }
            }
        };


        for(int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i);
            }
        }

        return ans;

    }
};