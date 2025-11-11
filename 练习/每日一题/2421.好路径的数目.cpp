#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        p.resize(n);
        size.resize(n, 1);
        maxVal.resize(n,0);
        maxCount.resize(n,1);
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

private:
    vector<int> p;
    vector<int> size;
    vector<int> maxVal; // 每个集合的最大值
    vector<int> maxCount; // 每个集合中最大值的个数


    vector<int> vals;
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int ans = n;
        //维护集合最大值和最大值个数
    }
};