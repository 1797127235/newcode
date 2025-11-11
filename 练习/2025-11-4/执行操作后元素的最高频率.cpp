//https://leetcode.cn/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/


#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

/*
差分
*/
class Solution1 {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> cnt;
        map<int, int> diff;
        for (int x : nums) {
            cnt[x]++;
            diff[x]; // 把 x 插入 diff，以保证下面能遍历到 x
            diff[x - k]++; // 把 [x-k, x+k] 中的每个整数的出现次数都加一
            diff[x + k + 1]--;
        }

        int ans = 0, sum_d = 0;
        for (auto& [x, d] : diff) {
            sum_d += d;
            ans = max(ans, min(sum_d, cnt[x] + numOperations));
        }
        return ans;
    }
};


/*
    二分 枚举元素
*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> cnt;
        int ans = 0;

        for(auto &x : nums){
            cnt[x]++;
        }
        for(auto &[x,y] : cnt) ans = max(ans,y);


        for(auto &x : nums)
        {
            int left = lower_bound(nums.begin(),nums.end(),x - k ) - nums.begin();
            int right = upper_bound(nums.begin(),nums.end(),x + k ) - nums.begin() - 1;
            int tmp;
            if(cnt.count(x))
            {
                tmp = min(right - left + 1,cnt[x] + numOperations);
            }
            else
            {
                tmp = min(right - left + 1,numOperations);
            }
            ans = max(ans,tmp);
        }
        return ans;
    }
};