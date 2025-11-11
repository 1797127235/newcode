//https://leetcode.cn/problems/minimum-operations-to-convert-all-elements-to-zero/description/
#include <bits/stdc++.h>
using namespace std;

/*
    单调栈
*/

class Solution1 {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> st;

        for(auto &x : nums)
        {
            while(!st.empty() && x < st.back())
            {
                st.pop_back();
                ans++;
            }

            if(st.empty() || x > st.back())
            {
                st.push_back(x);
            }
        }

        return ans + st.size() - (st.front() == 0 ? 1 : 0);
    }
};


/*
    次只考虑一种元素。如果两元素之间有其它更小的元素
    那么这两个元素无法在同一次操作内处理掉，答案加 1
*/


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        // f[i]：下标 i 右边最近的更小元素下标
        int f[n];
        for (int i = 0; i < n; i++) f[i] = n;
        // 用单调栈求
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                f[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        
        // 把下标按值分类，每次只考虑一种元素
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) mp[nums[i]].push_back(i);
        int ans = 0;
        for (auto &p : mp) {
            auto &vec = p.second;
            // 除了 0 以外，每种元素至少一次操作
            if (p.first > 0) ans++;
            // 两元素之间有更小元素，无法在一次操作内处理，答案再加 1
            for (int i = 0; i + 1 < vec.size(); i++) if (f[vec[i]] < vec[i + 1]) ans++;
        }
        return ans;
    }
};


#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    int n;
    vector<int> seg;     // 线段树数组，存区间最小值

    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n, INT_MAX);
        build(1, 0, n - 1, nums);
    }

    // 对外接口：查询区间 [l, r] 的最小值
    int Query(int l, int r) {
        if (l > r) return INT_MAX;
        return query(1, 0, n - 1, l, r);
    }

private:
    void build(int idx, int l, int r, const vector<int>& nums) {
        if (l == r) {
            seg[idx] = nums[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(idx << 1, l, mid, nums);
        build(idx << 1 | 1, mid + 1, r, nums);
        seg[idx] = min(seg[idx << 1], seg[idx << 1 | 1]);
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[idx];
        int mid = (l + r) >> 1;
        int res = INT_MAX;
        if (ql <= mid) res = min(res, query(idx << 1, l, mid, ql, qr));
        if (qr > mid)  res = min(res, query(idx << 1 | 1, mid + 1, r, ql, qr));
        return res;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> all; // 存储每个值对应的下标列表
        for (int i = 0; i < n; i++) {
            all[nums[i]].push_back(i);
        }

        int ans = 0;
        SegmentTree tree(nums); // 线段树：支持查询区间 [l, r] 的最小值

        // 分治
        auto dfs = [&](auto&& self, int l, int r) -> void {
            if (l > r) return;
            int mv = tree.Query(l, r);   // 当前区间最小值
            auto& list = all[mv];

            int pre = l;
            // 二分查找当前 [l, r] 区间内，该最小值 mv 出现的位置范围
            int posL = lower_bound(list.begin(), list.end(), l) - list.begin();
            int posR = upper_bound(list.begin(), list.end(), r) - list.begin();

            for (int i = posL; i < posR; i++) {
                int v = list[i];
                self(self, pre, v - 1); // 对 [pre, v-1] 再递归
                pre = v + 1;
            }
            // 最右边一段
            self(self, pre, r);

            // 当前这个区间整体减去 mv 一次，如果 mv > 0，操作数 +1
            if (mv > 0) ans++;
        };

        // 从整个区间 [0, n-1] 开始处理
        dfs(dfs, 0, n - 1);
        return ans;
    }
};

