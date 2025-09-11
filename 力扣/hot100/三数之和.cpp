#include<bits/stdc++.h>
using namespace std;

/*
    自以为很简单，实际根本不会做
    先排序
    枚举一个i点
    然后 j k 使用双指针

    为了去掉重复，需要跳过重复的值
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // nums[i] + nums[j] == -nums[k]
        map<int,int> mp;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i =0 ;i < n ;i++)
        {
            mp[nums[i]] = i;
        }
        vector<vector<int>> ans;

        for(int i =0 ; i < n; i++)
        {
            if(i-1>=0 && nums[i] == nums[i-1]) continue;
            int x = nums[i];
            int j = i + 1;
            int k = n - 1;

            while(j < k)
            {
                if(nums[j] + nums[k] + x > 0)
                {
                    k--;
                }
                else if(nums[j] + nums[k] + x < 0)
                {
                    j++;
                }
                else
                {
                    vector<int> t = {nums[i],nums[j],nums[k]};
                    ans.push_back(t);

                    while(j + 1 < k && nums[j+1] == nums[j]) j++;
                    while(k -1 > j && nums[k-1] == nums[k]) k--;
                    j++;
                    k--;
                }
            }
        }

        return ans;
    }
};