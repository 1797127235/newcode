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

//看有几个连通块
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int ans = 0;

        UnionFind uf(n);

        auto check = [&](const string& a, const string& b) {
            int cnt = 0;
            for(int i = 0; i < a.size(); ++i)
            {
                if(a[i] != b[i])
                    cnt++;
                if(cnt > 2)
                    return false;
            }

            return true;
        };

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n;j++)
            {
                if(check(strs[i], strs[j]) && uf.find(i) != uf.find(j))
                    uf.unite(i, j);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(uf.find(i) == i)
                ans++;
        }

        return ans;

    }
};