#include<bits/stdc++.h>
using namespace std;

/*
    贪心
    对于一段连续相同颜色的气球，只保留时间最大的，其他的都删除
*/
class Solution1 {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        //选一段连续相同颜色的气球，只保留时间最大的，其他的都删除

        int ans = 0;
        int i = 0;
        while(i < n)
        {
            int j = i;
            int maxTime =  neededTime[i];
            int sumTime = neededTime[i];
            while(j + 1 < n && colors[j + 1] == colors[i])
            {
                j++;
                maxTime = max(maxTime, neededTime[j]);
                sumTime += neededTime[j];
            }

            ans += (sumTime - maxTime);
            i = j + 1;
        }

        return ans;
    }
};

/*
    动态规划
*/


class Solution2 {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = (int)colors.size();
        if (n == 0) return 0;

        int keep = 0;                // 到 i-1 且保留 i-1
        int del  = neededTime[0];    // 到 i-1 且删除 i-1

        for (int i = 1; i < n; ++i) {
            int pk = keep, pd = del;
            if (colors[i] == colors[i - 1]) {
                keep = pd;
                del  = min(pk, pd) + neededTime[i];
            } else {
                keep = min(pk, pd);
                del  = min(pk, pd) + neededTime[i];
            }
        }
        return min(keep, del);
    }
};

/*
    动态规划
    dp[i][ch] 表示：从下标 i 开始、且以字母 ch 作为起始颜色的 最小删除代价。
    f(i, prev)：从下标 i 开始到末尾，且上一个被留下的颜色是 prev 时，达到合法最终序列的最小删除代价。
    当前状态 (i, prev)，根据输入颜色 cur，有两种转移到新的状态 (i+1, prev) 或 (i+1, cur)
*/
class Solution3 {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        const int NONE = 26;
        vector<array<int,27>> dp(n + 1);
        for (int k = 0; k < 27; ++k) dp[n][k] = 0;     // f(n, prev) = 0

        for (int i = n - 1; i >= 0; --i) {
            int cur = colors[i] - 'a';
            for (int prev = 0; prev <= 26; ++prev) {
                if (cur == prev)//当前颜色和上一个保留的颜色相同
                {
                    dp[i][prev] = neededTime[i] + dp[i + 1][prev];
                } 
                else//当前可以删除也可以保留  
                {
                    dp[i][prev] = min(neededTime[i] + dp[i + 1][prev],dp[i + 1][cur]);
                }
            }
        }

        //从第零个气球开始，前面没有保留气球
        return dp[0][NONE];
    }
};

/*
    记忆化搜索
*/
class Solution {
    static constexpr int NONE = 26;               // 特殊值：之前没留过
    string c;
    vector<int> t;
    vector<array<int, 27>> memo;                 // memo[i][prev]，prev ∈ 0..26

    int dfs(int i, int prev) {
        if (i == (int)c.size()) return 0;
        int &res = memo[i][prev];
        if (res != -1) return res;

        int cur = c[i] - 'a';
        int cost = t[i];
        if (cur == prev) {
            // 只能删当前
            res = cost + dfs(i + 1, prev);
        } else {
            // 删 or 留
            int del  = cost + dfs(i + 1, prev);
            int keep = dfs(i + 1, cur);
            res = min(del, keep);
        }
        return res;
    }

public:
    int minCost(string colors, vector<int>& neededTime) {
        c = colors; t = neededTime;
        int n = c.size();
        memo.assign(n, array<int,27>());
        for (auto &row : memo) row.fill(-1);
        return dfs(0, NONE);
    }
};
