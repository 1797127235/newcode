#include<bits/stdc++.h>
using namespace std;
/*
    直接暴力求，枚举需要添加的语言
*/
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size(); //一共存在多少人

        //第i个人是否学了第x道题目
        vector<vector<int>> learn(m,vector<int>(n+1,0));

        for(int i = 0 ; i < m ; i++)
        {
            for(auto &x : languages[i])
            {
                learn[i][x] = 1;
            }
        }

        vector<pair<int,int >> todo_list;

        for(auto &f : friendships)
        {
            int u = f[0] - 1, v = f[1] - 1;
            bool ok = false;
            for(int x : languages[u])
            {
                if(learn[v][x])
                {
                    ok = true;
                    break;
                }
            }
            if(!ok) todo_list.push_back({u,v});
        }

        int  ans = m;
        for(int  k = 1; k <= n ; k++)
        {
            unordered_set<int> st;
            for(auto &[u,v] : todo_list)
            {
                if(!learn[u][k]) st.insert(u);
                if(!learn[v][k]) st.insert(v);
            }
            ans = min(ans,(int)st.size());
        }
        return ans;
    }
};