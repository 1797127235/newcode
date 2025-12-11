#include <vector>
#include <deque>
using namespace std;
/*
    滑动窗口和单调队列

*/
class Solution {
public:
    int countPartitions(vector<int>& a, int k) {
        const int MOD = 1'000'000'007;
        int n = a.size(); 
        // 改成 1-based：创建一个新数组 nums[1..n]
        vector<int> nums(n + 1);
        for (int i = 1; i <= n; ++i) nums[i] = a[i - 1];
        vector<long long> dp(n + 1), pre(n + 1);
        dp[0] = 1;
        pre[0] = 1;
        deque<int> maxq, minq;
        int l = 1;  // 当前窗口左边界（1-based）
        for (int r = 1; r <= n; ++r) {
            // --- 更新单调队列（维护最大与最小） ---
            while (!maxq.empty() && nums[maxq.back()] <= nums[r]) maxq.pop_back();
            maxq.push_back(r);
            while (!minq.empty() && nums[minq.back()] >= nums[r]) minq.pop_back();
            minq.push_back(r);
            // --- 收缩窗口直到 max - min <= k ---
            while (!maxq.empty() && !minq.empty()
                   && nums[maxq.front()] - nums[minq.front()] > k) {

                if (maxq.front() == l) maxq.pop_front();
                if (minq.front() == l) minq.pop_front();
                l++;
            }
            int i = r;    // 注意：1-based，dp[i] 对应 nums[1..i]
            dp[i] = (pre[i - 1] - (l > 1 ? pre[l - 2] : 0) + MOD) % MOD;
            pre[i] = (pre[i - 1] + dp[i]) % MOD;
        }
        return dp[n];
    }
};
