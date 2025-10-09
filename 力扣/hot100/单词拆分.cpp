#include<bits/stdc++.h>
using namespace std;

//记忆化搜索 注意提前break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> mp(wordDict.begin(),wordDict.end());
        vector<int> meno(n + 1, -1);
        int mx = ranges::max(wordDict, {}, &string::length).length();
        s = '#' + s;
        auto dfs = [&](auto &&dfs,int u)->bool{
            if(u <= 0)
            {
                return true;
            }
            if(meno[u]!=-1) return meno[u];
            bool res = false;
            for(int j = u; j >= max(0,u+1-mx); j--)
            {
                if(mp.count(s.substr(j,u-j+1)) && dfs(dfs,j - 1))
                {
                    res = true;
                    break;
                }
            }
            meno[u] = res;
            
            return res;
        };
        return dfs(dfs,n); 
    }
};
