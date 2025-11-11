#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> sum(n);
        sum[0] = 0;
        for(int i = 1; i < n; i++)
        {
            sum[i] = nums[i] - nums[i - 1];
        }

        for(int i = 1;i < n;i++)
        {
            sum[i] = sum[i - 1] + sum[i];
        }

        int ans = 1;
        int l = 1,r = 1;
        long long cnt = 0;
        for(;r < n;r++)
        {
            cnt += sum[r];
            while(cnt > k)
            {
                cnt -= sum[l];
                l++;
            }
            ans = max(ans,r-l+2);
        }
        return ans;
    }
};