//https://leetcode.cn/problems/count-the-number-of-complete-components/

#include<bits/stdc++.h>
using namespace std;

/*
    统计完全连通分量的数量

    一个连通块两两两个点都能连通 有

    e = v*(v-1)/2 条边
*/

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<vector<int>> st;
        vector<int> tmp;
        vector<uint8_t> vis(n);
        auto dfs = [&](this auto &&dfs,int u) -> void{
            vis[u] = 1;
            tmp.push_back(u);
            for (auto &v : g[u]) {
                if (!vis[v])
                    dfs(v);
            }
        };

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                tmp.clear();
                dfs(i);
                st.push_back(tmp);
            }
        }

        //遍历每一个集合
        int ans = 0;
        for(auto &v : st)
        {
            bool flag = true;
            int sz = v.size();

            for(int i = 0; i < sz; ++i)
            {
                for(int j = i + 1; j < sz; ++j)
                {
                    int u1 = v[i], u2 = v[j];
                    //判断u1 u2是否有边
                    auto it = find(g[u1].begin(), g[u1].end(), u2);
                    if(it == g[u1].end())
                    {
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) ans++;
        }

        return ans;
    }
};