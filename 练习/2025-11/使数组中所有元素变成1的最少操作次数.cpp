//https://leetcode.cn/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/


#include <bits/stdc++.h>
using namespace std;


/*
    暴力解法
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int g = nums[0];
        for(auto &x : nums)
        {
            g = gcd(g,x);
        }
        if(g > 1) return -1;

        int cnt = 0;
        for(auto &x : nums)
        {
            if(x != 1) cnt++;
        }

        if(cnt !=n ) return cnt;



        //枚举子数组长度
        for(int l = 2; l <=n; ++l)
        {
            for(int i = 0; i + l - 1 < n; ++i)
            {
                int g = nums[i];
                for(int j = i; j <= i + l -1; ++j)
                {
                    g = gcd(g,nums[j]);
                }

                if(g == 1)
                {
                    return l - 1 + n - 1;
                }
            }
        }
        return -1;
    }
};


/*
    双指针
*/


class Solution {
public:
    int minOperations(vector<int>& nums) {
        
    }
};
