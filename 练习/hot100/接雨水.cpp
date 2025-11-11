#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int)height.size();
        if (n < 3) return 0;

        vector<int> pre(n), suf(n);
        pre[0] = height[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = max(pre[i - 1], height[i]);
        }

        suf[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = max(suf[i + 1], height[i]);
        }

        long long ans = 0; // 防止中间和溢出
        for (int i = 1; i < n - 1; ++i) {
            int t = min(pre[i - 1], suf[i + 1]); // 不含自身的左右最高
            if (height[i] < t) ans += (t - height[i]);
        }
        return (int)ans;
    }
};
