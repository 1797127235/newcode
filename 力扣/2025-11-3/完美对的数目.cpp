// https://leetcode.cn/problems/number-of-perfect-pairs/description/


#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        //ranges::sort(nums);
        for(auto &x : nums)
        {
            if(x < 0) x = -x;
        }
        sort(nums.begin(),nums.end());
        long long ans = 0;

        /*
            对于数 a,b 满足 abs(a) <= abs(b) <= 2 * abs(a)
            第二个条件是多余的
        */

        for(int i = 0; i < n; i++)
        {
            int left = lower_bound(nums.begin() + i + 1,nums.end(),nums[i]) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1,nums.end(),nums[i] * 2) - nums.begin();

            if(left <= right)
            ans += right - left;
        }

        return ans;
    }
};