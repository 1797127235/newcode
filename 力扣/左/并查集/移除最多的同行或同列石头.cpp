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
            

            //成功合并两个集合，连通块数减去一`
            cnt--;
        }
    }
private:
    vector<int> p;
    vector<int> size;
};
//同行或者同列的石头可以连通
// 一个连通块有x个石头，可以移除x-1个石头
// 移除的最大石头数 = 总石头数 - 连通块数
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);
        unordered_map<int, int> row;
        unordered_map<int, int> col;

        for(int i = 0; i < n; i++)
        {
            int r = stones[i][0];
            int c = stones[i][1];

            if(row.count(r))
            {
                uf.unite(i,row[r]);
            }
            else
            {
                row[r] = i;
            }

            if(col.count(c))
            {
                uf.unite(i,col[c]);
            }
            else
            {
                col[c] = i;
            }
        }

        return n - cnt;
    }
};