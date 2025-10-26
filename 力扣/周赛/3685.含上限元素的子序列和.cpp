#include<bits/stdc++.h>
using namespace std;

/*
    01背包
    限制数组是原数组的一段前缀，加上若干个被视为上限的元素

    枚举选了y个被视为上限的元素，后缀部分的元素和就是x*y,为了让整个数组选出和为k的
    元素，前缀部分就要选出和为k - x*y的元素

*/
class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int K) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        bool f[K + 1];
        memset(f, 0, sizeof(f));
        f[0] = true;

        // 上限为 x，且有 y 个元素超出上限的数组，能否组合出 k
        auto check = [&](int x, int y) {
            // 枚举选几个超出上限的元素
            for (int i = 0; i <= y; i++) { //枚举选几个超出上限的
                int det = K - x * i;
                if (det < 0) break;
                // 看前缀能否组合出差值
                if (f[det]) return true;
            }
            return false;
        };

        vector<bool> ans;
        // 所有元素都超出上限的情况
        for (int i = 1; i < nums[0]; i++) ans.push_back(check(i, n));
        // 01 背包求前 i 个数能组合出几种元素和
        for (int i = 0; i < n; i++) {
            for (int j = K; j >= nums[i]; j--) if (f[j - nums[i]]) f[j] = true;

            // 前 i 个元素不超出上限的情况
            // 对所有 x ∈ [nums[i], next-1]，后缀大小都是 y = n-1-i
            int next = (i+1 < n ? nums[i+1] : n+1);
            for (int x = nums[i]; x <= next - 1; ++x)
                ans.push_back(check(x, n-1-i));
        }
        return ans;
    }
};