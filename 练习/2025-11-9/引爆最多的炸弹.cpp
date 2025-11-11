//https://leetcode.cn/problems/detonate-the-maximum-bombs/


#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        /*
            枚举引爆哪一个炸弹
        */

        // 距离  需要
        vector<vector<pair<int,long long>>> g(n);

        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                
                double dis = (1L*(bombs[j][0] - bombs[i][0]) * (bombs[j][0] - bombs[i][0]) + 1L*(bombs[j][1] - bombs[i][1]) * (bombs[j][1] - bombs[i][1]));
                g[i].emplace_back(j,dis);
                g[j].emplace_back(i,dis);
            }
        }

        int ans = 1;
        int cnt = 0;
        vector<uint8_t> vis(n,0);
        function<void(int)> dfs =[&](int u){
            vis[u] = 1;
            cnt++;
            for(auto& [to,dis] : g[u])
            {
                if(vis[to]) continue;
                if(dis <= 1L * bombs[u][2] * bombs[u][2])
                {
                    dfs(to);
                }
            }
        };

        for(int i = 0; i < n; ++i)
        {
            fill(vis.begin(), vis.end(), 0);
            cnt = 0;
            dfs(i);
            ans = max(ans,cnt);
        }

        return ans;

    }
};

/*
    定义f[i]为可以到达的节点集合，f[k]为k可以到达的集合
    当i能到达k时，那么i就能到达k所能到达的节点
    f[i] = f[i] + f[k]
*/

class Solution {
public:

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        vector<bitset<100>> f(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n;j++)
            {
                int dx = bombs[j][0] - bombs[i][0];
                int dy = bombs[j][1] - bombs[i][1];
                if(1L * dx * dx + 1L * dy * dy <= 1L * bombs[i][2] * bombs[i][2])
                {
                    f[i].set(j);
                }
            }
        }

        for(int k = 0; k < n;k++)
        {
            for(auto &fi : f)
            {
                if(fi[k]) fi |= f[k];
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans,(int)f[i].count());
        }
        return ans;
    }
};