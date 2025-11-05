//https://leetcode.cn/problems/move-zeroes/description/

#include<bits/stdc++.h>
using namespace std;

/*
    将非零元素移动到前面
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j = 0; j < n;j++)
        {
            if(nums[j] != 0)
            {
                nums[i] = nums[j];
                i++;
            }
        }

        for(int j = i; j < n;j++)
        {
            nums[j] = 0;
        }
    }
};