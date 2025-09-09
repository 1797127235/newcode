#include<bits/stdc++.h>
using namespace std;

/*
dp[i][j]: 第 i 天时，已知秘密“恰好 j 天”的人数
dp[i][1] = dp[i-1][delay] + dp[i-1][delay+1] + ... + dp[i-1][forget-1]
 */
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        using int64 = long long;
        vector<vector<int>> dp(n+1,vector<int>(forget+1,0));
        dp[1][1] = 1;
        for(int i = 2; i<=n; i++)
        {
            for(int j = 2;j<=forget; j++)
            {
                dp[i][j] = dp[i-1][j-1];
            }

            int64 add = 0;

            for(int k = delay; k<=forget-1; k++)
            {
                add+=dp[i-1][k];
                if(add >= MOD) add -= MOD;
            }
            dp[i][1] = add;
        }

        int64 ans = 0;
        for(int j = 1; j<=forget; j++)
        {
            ans+=dp[n][j];
            if(ans>=MOD) ans-=MOD;
        }
        return int(ans);
    }
};
