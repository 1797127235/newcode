#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        // best：把哪个数追加到 nums2 末尾
        int best = 1e9;
        // 看看 x 是不是比 best 更接近 nums2[n]
        auto update = [&](int x) {
            if (abs(best - nums2[n]) > abs(x - nums2[n])) best = x;
        };

        long long ans = 1;
        for (int i = 0; i < n; i++) {
            // 这个元素的变化区间为 [l, r]
            int l = min(nums1[i], nums2[i]);
            int r = max(nums1[i], nums2[i]);
            ans += r - l;
            // 如果 nums2 末尾元素恰好位于变化区间内，直接把它追加到末尾
            if (l <= nums2[n] && nums2[n] <= r) best = nums2[n];
            // 否则变化区间的端点离 nums2[n] 更近，选一个近的
            else update(l), update(r);
        }
        
        ans += abs(best - nums2[n]);
        return ans;
    }
};