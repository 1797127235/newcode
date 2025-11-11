//https://leetcode.cn/problems/living-people-lcci/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int n = birth.size();

        vector<int> diff(102,0);

        for(int i = 0; i < n; ++i)
        {
            diff[birth[i] - 1900]++;
            diff[death[i] - 1900 + 1]--;
        }

        int anscnt = diff[0];
        int ans = 1900;
        for(int i = 1; i < 102; ++i)
        {
            diff[i] += diff[i - 1];
            if(diff[i] > anscnt)
            {
                anscnt = diff[i];
                ans = i + 1900;
            }
        }

        return ans;
    }
};