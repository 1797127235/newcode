//https://leetcode.cn/problems/couples-holding-hands/description/
#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
class UnionFind
{
public:
    UnionFind(int n)
    {
        p.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            p[i] = i;
        cnt = n;
    }

    int find(int x)
    {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (size[rootX] < size[rootY])
                swap(rootX, rootY);
            p[rootY] = rootX;
            size[rootX] += size[rootY];
            cnt--;
        }
    }
private:
    vector<int> p;
    vector<int> size;
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        UnionFind uf(n / 2);

        for(int i = 0; i < n ; i += 2)
        {
            int a = row[i] / 2;
            int b = row[i + 1] / 2;
            uf.unite(a, b);
        }

        return (n / 2) - cnt;
    }
};