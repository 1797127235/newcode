#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        deque<int> maxdq, mindq;     // 存下标：maxdq 递减，mindq 递增
        long long ans = 0;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            // 维护最大值队列
            while (!maxdq.empty() && nums[r] > nums[maxdq.back()]) maxdq.pop_back();
            maxdq.push_back(r);
            // 维护最小值队列
            while (!mindq.empty() && nums[r] < nums[mindq.back()]) mindq.pop_back();
            mindq.push_back(r);

            // 收缩左端，直到满足 max-min <= 2
            while (!maxdq.empty() && !mindq.empty() &&
                   nums[maxdq.front()] - nums[mindq.front()] > 2) {
                if (maxdq.front() == l) maxdq.pop_front();
                if (mindq.front() == l) mindq.pop_front();
                ++l;
            }

            ans += (r - l + 1);  // 以 r 结尾的合法子数组个数
        }
        return ans;
    }
};