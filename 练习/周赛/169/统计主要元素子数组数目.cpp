//https://leetcode.cn/contest/biweekly-contest-169/problems/count-subarrays-with-majority-element-ii/


#include<bits/stdc++.h>

using namespace std;

using ll = long long;
struct Fenwick {
    int n;
    vector<ll> bit;  

    Fenwick(int n) : n(n), bit(n + 1, 0)
    {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void add(int idx, ll val) {
        for (int i = idx; i <= n; i += lowbit(i)) {
            bit[i] += val;
        }
    }

    ll sum(int idx)
    {
        ll res = 0;
        for (int i = idx; i > 0; i -= lowbit(i)) {
            res += bit[i];
        }
        return res;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        ll ans = 0;
        vector<int> new_nums(n + 1);
        for(int i = 0; i < n;i++){
            if(nums[i] == target) new_nums[i + 1] += 1;
            else new_nums[i + 1] -= 1;
        }

        for(int i = 1; i <= n; i++){
            new_nums[i] += new_nums[i - 1];
        }

        // 子数组和大于0

        auto t = new_nums;
        sort(t.begin(),t.end());
        t.erase(unique(t.begin(),t.end()),t.end());

        auto getid = [&](ll x)
        {
            return lower_bound(t.begin(),t.end(),x) - t.begin() + 1;
        };

        Fenwick f(t.size());

        f.add(getid(new_nums[0]),1);

        for(int i = 1; i <= n; i++)
        {
            int id = getid(new_nums[i]);
            ans = ans + f.sum(id - 1);

            f.add(id,1);
        }

        return ans;

    }
};