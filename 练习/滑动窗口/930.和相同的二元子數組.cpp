#include<bits/stdc++.h>
using namespace std;
//统计“和 ≤ goal 的子数组个数” 减去 “和 ≤ goal-1 的子数组个数
//差值就是“和 = goal 的子数组个数”

//固定右端點
//所有以right結尾且和<=goal的子數組，他們的左端可以從left1到right
//所有以right結尾且和<=goal-1的子數組，他們的左端可以從left2到right
//left2>=left1
//兩者的可選左端個數相減,(left2 - left1)，就是和 = goal的子數組個數
//https://leetcode.cn/problems/binary-subarrays-with-sum/description/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int left1 = 0, left2 = 0, right = 0;
        int sum1 = 0, sum2 = 0;
        int ret = 0;
        while (right < n) {
            sum1 += nums[right];
            // <= goal
            while (left1 <= right && sum1 > goal) {
                sum1 -= nums[left1];
                left1++;
            }
            sum2 += nums[right];
            // <=goal - 1
            while (left2 <= right && sum2 >= goal) {
                sum2 -= nums[left2];
                left2++;
            }
            ret += left2 - left1;
            right++;
        }
        return ret;
    }
};
