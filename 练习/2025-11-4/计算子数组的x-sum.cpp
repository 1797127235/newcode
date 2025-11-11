//https://leetcode.cn/problems/find-x-sum-of-all-k-long-subarrays-i
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        using pii = pair<int,int>;

        set<pii> L,R;
        long long sum_l = 0;
        unordered_map<int,int> cnt;
        auto add = [&](int x)
        {
            pii p = {cnt[x],x};
            if(p.first == 0)
            {
                return ;
            }

            if(!L.empty() && p > *L.begin())
            {
                sum_l += (long long)p.first * p.second;
                L.insert(p);
            }
            else
            {
                R.insert(p);
            }
        };

        auto del = [&](int x)
        {
            pii p = {cnt[x],x};
            if(p.first == 0) return;
            auto it = L.find(p);
            if(it != L.end())
            {
                sum_l -= (long long)p.first * p.second;
                L.erase(it);
            }
            else
            {
               auto itr = R.find(p);
               if(itr != R.end())
               {
                R.erase(itr);
               }
            }
        };

        //把L里最差的丢给R,并扣除它的贡献
        auto l2r = [&]() {
            pii p = *L.begin();
            sum_l -= (long long) p.first * p.second;
            L.erase(p);
            R.insert(p);
        };
        //把R里最好的丢给L,并增加它的贡献
        auto r2l = [&]() {
            pii p = *R.rbegin();
            sum_l += (long long) p.first * p.second;
            R.erase(p);
            L.insert(p);
        };

        vector<long long> ans(nums.size() - k + 1);

        for(int  r = 0;r < nums.size();r++)
        {
            int in = nums[r];
            del(in);
            cnt[in]++;
            add(in);
            int l = r + 1 - k;
            if(l < 0) continue;

            while(!R.empty() && L.size() < x)
            {
                r2l();
            }
            while(L.size() > x)
            {
                l2r();
            }
            ans[l] = sum_l;

            int out = nums[l];
            del(out);
            cnt[out]--;
            add(out);
        }

        return ans;
    }
};