
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;

        unordered_map<int, vector<int>> pos;

        for(int i = 0; i < n; i++)
        {
            pos[nums[i]].push_back(i);
        }


        for(auto &x : pos)
        {
            if(x.second.size() < 3) continue;

            auto &v = x.second;

            for(int i = 1; i + 1 < v.size(); i++)
            {
                ans = min(ans, abs(v[i] - v[i - 1])+ abs(v[i] - v[i + 1]) + abs(v[i + 1] - v[i - 1]));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};