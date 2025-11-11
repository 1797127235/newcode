//https://leetcode.cn/problems/ones-and-zeroes/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[605][110][110];
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        memset(dp,0,sizeof dp);
        vector<int> zero(len + 1,0);

        for(int i = 0; i < len; ++i)
        {
            int cnt0 = 0;
            for(auto c : strs[i])
            {
                if(c == '0') cnt0++;
            }
            zero[i + 1] = cnt0;
        }
        dp[0][0][0] = 0;
        //每个字符串有选或者不选
        for(int i = 1; i <= len; ++i)
        {
            int cnt1 = strs[i - 1].size() - zero[i];
            for(int j = 0; j <= m; ++j)
            {
                for(int k = 0; k <= n ;++k)
                {
                    dp[i][j][k] = max(dp[i - 1][j][k],dp[i][j][k]);
                    if(j >= zero[i] && k >= cnt1)
                    {
                        dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j - zero[i]][k - cnt1] + 1);
                    }
                }
            }
        }

        return dp[len][m][n];
    }
};