//https://leetcode.cn/problems/find-all-people-with-secret/description/

#include <bits/stdc++.h>
using namespace std;



class UnionFind {
public:
    UnionFind(int n) {
        p.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) p[i] = i;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) swap(rootX, rootY);
            p[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    int getSize(int x) {
        return size[find(x)]; // 返回 x 所在集合的大小
    }


    void reset(int x)
    {
        p[x] = x;
        size[x] = 1;
    }

private:
    vector<int> p;
    vector<int> size;
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // 已知秘密的人
        vector<int> know(n, 0);
        know[0] = know[firstPerson] = 1;

        // 按时间排序
        sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b){
            return a[2] < b[2];
        });

        UnionFind uf(n);
        int i = 0, m = meetings.size();
        while (i < m) {
            int t = meetings[i][2];
            // 收集同一时刻的所有会议
            int j = i;
            vector<int> persons;  // 本时刻出现过的人（用于回滚）
            unordered_set<int> seen;
            while (j < m && meetings[j][2] == t) {
                int x = meetings[j][0], y = meetings[j][1];
                uf.unite(x, y);
                if (!seen.count(x)) { persons.push_back(x); seen.insert(x); }
                if (!seen.count(y)) { persons.push_back(y); seen.insert(y); }
                ++j;
            }

            // 统计每个连通块是否包含“本时刻开始前”的已知者
            unordered_map<int, bool> hasKnower;
            for (int v : persons) {
                int r = uf.find(v);
                hasKnower[r] = hasKnower[r] || know[v];
            }

            // 把该连通块内的人全部标记为已知（如果该块里有人已知）
            for (int v : persons) {
                if (hasKnower[uf.find(v)]) know[v] = 1;
            }

            // 回滚：清除本时刻的临时连通关系
            for (int v : persons) uf.reset(v);

            i = j;
        }

        vector<int> ans;
        for (int v = 0; v < n; ++v) if (know[v]) ans.push_back(v);
        return ans;
    }
};