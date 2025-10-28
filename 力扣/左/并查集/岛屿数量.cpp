#include<bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    UnionFind(int n)
    {
        p.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            p[i] = i;
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
        }
    }
private:
    vector<int> p;
    vector<int> size;
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        UnionFind unite(m * n + 1);
        

        for(int i = 0;i < m;i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(grid[i][j] == '0')
                    continue;
                int x = i*n + j;

                for(int k = 0; k < 4;k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1')
                    {
                        int y = nx * n + ny;
                        unite.unite(x, y);
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(grid[i][j] == '1')
                {
                    int x = i*n + j;
                    if(unite.find(x) == x)
                        ans++;
                }
            }
        }
        


    }
};