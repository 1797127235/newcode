//https://leetcode.cn/problems/couples-holding-hands/description/
#include<bits/stdc++.h>
using namespace std;
/*
    并查集做法
    置换换的最少交换次数 = 每个环的元素个数 - 1
    累加得环的总数 - 环的数量
    每次合并能使得环的数量减少1
*/
class UnionFind {
public:
    UnionFind(int n) {
        p.resize(n);
        size.resize(n, 1);
        cnt = n;
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
            cnt--;
        }
    }

    int getSize(int x) {
        return size[find(x)]; // 返回 x 所在集合的大小
    }

    int getcnt() {
        return cnt;
    }

private:
    vector<int> p;
    vector<int> size;
    //刚i开始的集合数量
    int cnt;
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        UnionFind uf(n / 2);
        for (int i = 0; i < n; i += 2)
        {
            int x = row[i] / 2;
            int y = row[i + 1] / 2;
            uf.unite(x, y);
        }

        return n - uf.getcnt();


    }
};



/*
    贪心
    
*/