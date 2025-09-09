#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int ans = 0;
        while(l < r)
        {
            if(height[l] < height[r]) ans = max(ans,(r - l) * height[l]),l++;
            else ans = max(ans,(r - l)*height[r]),r--;
        }
        return ans;
    }
};