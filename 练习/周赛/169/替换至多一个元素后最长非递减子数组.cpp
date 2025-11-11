//https://leetcode.cn/contest/biweekly-contest-169/problems/longest-non-decreasing-subarray-after-replacing-at-most-one-element/description/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> dppre(n + 1, 1);
        vector<int> dpsuf(n + 1,1);
        int ans = 1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] >= nums[i - 1]) dppre[i] = dppre[i - 1] + 1;

            ans = max(ans,dppre[i]);
        }

        for(int i = n - 2; i >=0; i--)
        {
            if(nums[i] <= nums[i + 1]) dpsuf[i] = dpsuf[i + 1] + 1;
        }

        ans = max(ans,dpsuf[1] + 1);

        ans =max(ans,dppre[n - 2] + 1);



        // 枚举中间
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i - 1] <= nums[i + 1])
            {
                ans = max(ans, dppre[i - 1] + dpsuf[i + 1] + 1);
            }
            else
            {
                ans = max(ans, dppre[i - 1] + 1);
                ans = max(ans, dpsuf[i + 1] + 1);
            }
        }

        return ans;
        
    }
};