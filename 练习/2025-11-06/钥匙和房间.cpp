//https://leetcode.cn/problems/keys-and-rooms/description/

#include <bits/stdc++.h>
#include <functional>

using namespace std;


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<uint8_t> vis(n);
        int cnt = 0;

        std::function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            cnt++;
            for(int &v : rooms[u])
            {
                if(vis[v]) continue;
                dfs(v);
            }
        };
        dfs(0);
        return cnt == n;
    }
};