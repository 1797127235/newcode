//https://leetcode.cn/problems/maximize-amount-after-two-days-of-conversions/description/
#include<bits/stdc++.h>
using namespace std;

/*
    根据pairs1和rates1构建图，使用DFS计算第一天每种货币的最大数量

    从 initialCurrency 开始，自顶向下 DFS 这张图，递归的同时维护金额。记录把 initialCurrency 兑换成其他货币的金额 day1Amount

    同理，根据 pairs2 和 rates2 构建图，计算第二天每种货币的最大数量 day2Amount

    遍历 day2Amount 中的每一种货币 x，计算 day1Amount[x] / day2Amount[x] 的最大值，即为答案
*/
//好难不会

class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {  
        auto calc_amount = [&](vector<vector<string>>& pairs, vector<double>& rates)-> unordered_map<string, double> {
            unordered_map<string, vector<pair<string, double>>> g;
            for (int i = 0; i < pairs.size(); i++) {
                auto& p = pairs[i];
                double r = rates[i];
                g[p[0]].emplace_back(p[1], r);
                g[p[1]].emplace_back(p[0], 1 / r);
            }

            unordered_map<string, double> amount;
            auto dfs = [&](this auto&& dfs, const string& x, double cur_amount) -> void {
                amount[x] = cur_amount;
                for (auto& [to, rate] : g[x]) {
                    if (!amount.contains(to)) {
                        dfs(to, cur_amount * rate);
                    }
                }
            };
            dfs(initialCurrency, 1);
            return amount;
        };

        auto day1_amount = calc_amount(pairs1, rates1);

        auto day2_amount = calc_amount(pairs2, rates2);

        double ans = 0;
        for (auto& [x, a2] : day2_amount) {
            ans = max(ans, day1_amount[x] / a2);
        }
        return ans;
    }
};