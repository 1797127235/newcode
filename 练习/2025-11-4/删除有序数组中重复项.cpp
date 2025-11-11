//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int bg = 0;
        int ed = 0;
        while(bg < n)
        {
            while(ed + 1 < n && nums[ed + 1] == nums[bg])
            {
                ed++;
            }
            nums[i] = nums[ed];
            i++;
            bg = ed + 1;
        }
        return i ;

    }
};