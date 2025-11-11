#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),[&](vector<int>& a,vector<int>& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int n = intervals.size();
        int i = 0;
        while(i < n)
        {
            int cur_right = intervals[i][1];
            int j = i;

            while(j  < n && intervals[j][0] <= cur_right)
            {
                cur_right = max(cur_right ,intervals[j][1]);
                j ++;
            }


            vector<int> t(2,0);
            t[0] = intervals[i][0];
            t[1] = cur_right;
            ans.push_back(t);
            i = j;

        }
        return ans;
    }
};