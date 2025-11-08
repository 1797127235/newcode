#include<bits/stdc++.h>
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

private:
    vector<int> p;
    vector<int> size;
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        UnionFind uf(c + 1);
        vector<uint8_t> online(c + 1, 1);
        for(auto &e : connections)
        {
            uf.unite(e[0],e[1]);
        }
        vector<set<int>> st(c + 1);

        for(int i = 1;i <= c;i++)
        {
            int root = uf.find(i);
            st[root].insert(i);
        }

        vector<int> ans;

        for(auto &q : queries)
        {
            int op = q[0];
            int x = q[1];
            if(op == 1)
            {
                int root = uf.find(x);
                if(st[root].size())
                {
                    if(st[root].count(x))
                    {
                        ans.push_back(x);
                    }
                    else
                    {
                        ans.push_back(*st[root].begin());
                    }
                }
                else
                {
                    ans.push_back(-1);
                }
            }
            else
            {
                online[x]=0;
                int root = uf.find(x);
                st[root].erase(x);
            }
        }
        return ans;
    }
};