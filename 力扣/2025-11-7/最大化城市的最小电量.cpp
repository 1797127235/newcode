//https://leetcode.cn/problems/maximize-the-minimum-powered-city/description/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    using ll = long long;
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        /*
            差分 + 二分答案
        */

        //先处理出每个位置的初始电量
        vector<ll> power(n + 1);
        for(int i = 0;i < n;i++)
        {
            int l = max(0, i - r);
            int rr = min(n - 1, i + r);
            power[l] += stations[i];
            power[rr + 1] -= stations[i];
        }

        for(int i = 1;i < n;i++)
        {
            power[i] += power[i - 1];
        }

        //二分最小电量的最大值
        auto check = [&](ll mid) -> bool{
            vector<ll> diff(n + 1);
            ll sum_d = 0;
            int kk = k;

            for(int i = 0; i < n; i++)
            {
                sum_d +=diff[i];
                ll cur_power = power[i] + sum_d;
                if(cur_power < mid)
                {
                    //当前需要额外建造的电站
                    ll need = mid - cur_power;
                    if(need > kk) return false;
                    kk -= need;
                    diff[min(n - 1, i + r)] += need;

                    diff[min(n, i + r + r + 1)] -= need;
                }
            }

            return true;
        };

        ll left = 0;
        ll right = 1e18;
        while(left < right)
        {
            ll mid = (left + right + 1) >> 1;
            if(check(mid)) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};