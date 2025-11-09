#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, INT_MIN + 1)));
        function<int(int,int,int)> dfs = [&](int x, int y, int cost) -> int {
            int val = grid[x][y];
            int curcost  = (val > 0 ? 1 : 0); 
            int curscore = val;               
            cost += curcost;
            if (cost > k) return INT_MIN;     
            if(dp[x][y][cost] != INT_MIN + 1) return dp[x][y][cost];
            if (x == m - 1 && y == n - 1) 
            {
                return curscore;              
            }

            int res = INT_MIN;

            if (x + 1 < m) 
            {
                int tmp = dfs(x + 1, y, cost);
                if (tmp != INT_MIN) {
                    res = max(res, curscore + tmp);
                }
            }
            if (y + 1 < n) 
            {
                int tmp = dfs(x, y + 1, cost);
                if (tmp != INT_MIN) {
                    res = max(res, curscore + tmp);
                }
            }
            dp[x][y][cost] = res;
            return res;
        };

        int ans = dfs(0, 0, 0);
        return ans == INT_MIN ? -1 : ans;
    }
};
