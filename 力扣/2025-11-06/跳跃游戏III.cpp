//https://leetcode.cn/problems/jump-game-iii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<uint8_t> vis(n,0); 
        auto dfs = [&](this auto &&dfs,int u)
        {
            vis[u] = 1;
            if(arr[u] == 0)
            {
                return true;
            }
            bool res = false;

            if(u + arr[u] < n && !vis[u + arr[u]]) res |= dfs(u + arr[u]);
            if(u - arr[u] >= 0 && !vis[u - arr[u]]) res |= dfs(u - arr[u]);

            return res;
        };

        return  dfs(start);
    }
};