//https://leetcode.cn/problems/count-subarrays-with-median-k/

#include<bits/stdc++.h>
using namespace std;



/*
    中位数为k的子数组的数量

    左侧小于 + 右侧小于 + 1 <= 左侧大于 + 右侧大于
    左侧小于 - 左侧大于 + 1 <= 右侧大于 - 右侧小于
*/
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;
        int balance = 0;
        map<int,int> cnt;
        int pos = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == k)
            {
                pos = i;
                break;
            }
        }

        for(int i = pos - 1; i >=0; i--)
        {
            if(nums[i] < k)
            {
                balance++;
            }
            else if(nums[i] > k)
            {
                balance--;
            }
            cnt[balance]++;
        }
        cnt[0]++;

        balance = 0;
        for(int i = pos; i < n; i++)
        {
            if(nums[i] < k)
            {
                balance--;
            }
            else if(nums[i] > k)
            {
                balance++;
            }

            ans = ans + cnt[balance] + cnt[balance - 1];
        }

        return ans;
    }
};