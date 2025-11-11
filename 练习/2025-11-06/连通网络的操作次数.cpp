//https://leetcode.cn/problems/number-of-operations-to-make-network-connected/
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
        {
            return -1;
        }
        //最小生成树
        UnionFind uf(n);
        for(auto &e : connections)
        {
            uf.unite(e[0],e[1]);
        }

        set<int> st;
        for(int i = 0; i < n; i++)
        {
            st.insert(uf.find(i));
        }
        //if(st.size() == 1) return 0;

        return st.size() - 1;
        
    }
};
