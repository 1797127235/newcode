#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

class FenwickTree {
private:
    vector<long long> bit;
    int n;
public:
    FenwickTree(int size) : n(size) {
        bit.resize(n + 1, 0);
    }

    void update(int index, long long delta) {
        while (index <= n) {
            bit[index] += delta;
            index += index & -index;
        }
    }

    long long query(int index) {
        long long sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & -index;
        }
        return sum;
    }

};

class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        int n = nums.size();
        //坐标压缩
        vector<int> c = nums;
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        int m = c.size();
        auto getid = [&](int x) {
            return lower_bound(c.begin(), c.end(), x) - c.begin() + 1;
        };

        for (int i = 0; i < n; i++) {
            nums[i] = getid(nums[i]);
        }


        FenwickTree fen(m + 1);

        long long ans = 1e18;
        
        long long cur = 0;
        for(int i = 0; i < k; i++)
        {
            int x = nums[i];
            cur = cur + fen.query(m) - fen.query(x);
            fen.update(x, 1);

        }
        ans = min(ans,(long long)cur);

        for(int i = k; i < n;i++)
        {
            int x = nums[i];
            fen.update(nums[i - k], -1);
            //出窗口的贡献
            cur = cur - fen.query(nums[i - k] - 1);
            //进窗口的贡献
            cur = cur + fen.query(m) - fen.query(x);
            fen.update(x, 1);
            ans = min(ans,(long long)cur);
        }

        return ans;
    }
};