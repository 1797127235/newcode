#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        
        for (int i = n - k; i < n; i++) { // 枚举终点 i
            int suf_sum = 0;
            for (int j = i; j >= 0; j -= k) {
                suf_sum += energy[j]; // 计算后缀和
                ans = max(ans, suf_sum);
            }
        }
        return ans;
    }
};
