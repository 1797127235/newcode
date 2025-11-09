//https://leetcode.cn/problems/minimize-malware-spread/description/
#include<bits/stdc++.h>
using namespace std;

/*
    奇奇怪怪就做出来了
    暴力大法
*/
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<vector<int>> g(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][j] == 1 && i != j) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int anscnt = INT_MAX;
        int ans = -1;
        for(int i = 0; i < initial.size(); i++)
        {
            vector<uint8_t> vis(n,0);
            int cnt = 0;
            queue<int> q;
            for(int j = 0; j < initial.size(); j++)
            {
                if(j == i) continue;
                vis[initial[j]] = 1;
                q.push(initial[j]);
            }

            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                cnt++;
                for(auto& to : g[u])
                {
                    if(!vis[to])
                    {
                        vis[to] = 1;
                        q.push(to);
                    }
                }
            }

            if(cnt < anscnt)
            {
                anscnt = cnt;
                ans = initial[i];
            }
            if(cnt == anscnt)
            {
                ans = min(ans,initial[i]);
            }
        }
        return ans;
    }
};



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
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<vector<int>> g(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][j] == 1 && i != j) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        UnionFind uf(n);
        vector<int> initialcnt(n,0);
        vector<uint8_t> vis(n,0);

        function<void(int)> dfs = [&](int u)
        {
            vis[u] = 1;
            for(auto& to : g[u])
            {
                if(!vis[to])
                {
                    uf.unite(u,to);
                    dfs(to);
                }
            }
        };

        for(auto &x : initial)
        {
            if(!vis[x])
            {
                dfs(x);
            }
        }

        for(auto &x : initial)
        {
            int fx = uf.find(x);
            initialcnt[fx]++;
        }

        int anscnt = -1;
        int ans = -1;

        for(auto &x : initial)
        {
            int fx = uf.find(x);
            if(initialcnt[fx] == 1)
            {
                int sz = uf.getSize(fx);
                if(sz > anscnt)
                {
                    anscnt = sz;
                    ans = x;
                }
                else if(sz == anscnt)
                {
                    ans = min(ans,x);
                }
            }
        }

        return ans == -1 ? *min_element(initial.begin(), initial.end()) : ans;
    }
};






