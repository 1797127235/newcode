#include<bits/stdc++.h>
using namespace std;

//二分 前缀和
//枚举左端点，二分找最小右端点
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); 
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        //枚举左端点二分找最小右端点
        for (int i = 1; i <= n; i++) {
            int target = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), target);
            if (bound != sums.end()) {
                ans = min(ans, int((bound - sums.begin()) - (i - 1)));
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

//滑动窗口

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;
        int l = 0;
        int cnt = 0;
        for(int r = 0; r < n; r++)
        {
            cnt += nums[r];
            while(cnt >= target)
            {
                ans = min(ans,r - l + 1);
                cnt -= nums[l];
                l++;
            }
        }
        return ans == 1e9 ? 0 : ans;
    }
};