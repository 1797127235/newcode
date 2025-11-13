//https://leetcode.cn/problems/find-subarray-with-bitwise-or-closest-to-k/


#include <bits/stdc++.h>
using namespace std;


class Solution1 {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        for(int r = 0; r < n; ++r)
        {
            ans = min(ans,abs(k - nums[r]));
            int x = nums[r];
            for(int l = r - 1; l >=0; --l)
            {
                nums[l] |= x;
                if(nums[l] | x == nums[l]) break;


                ans = min(ans,abs(k - nums[l]));
            }
        }


        return ans;
    }
};



//https://leetcode.cn/problems/smallest-subarrays-with-maximum-bitwise-or/description/


class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        
    }
};

