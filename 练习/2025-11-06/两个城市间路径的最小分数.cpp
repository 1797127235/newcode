//https://leetcode.cn/problems/minimum-score-of-a-path-between-two-cities/description/


#include<bits/stdc++.h>
using namespace std;
/*
    求连通块的最小边
    bfs
    dfs
*/
class Solution {
public:
    using P = pair<int,int>; 

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n + 1);
        for (auto &e : roads) {
            int u=e[0], v=e[1], w=e[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        const int INF = INT_MAX;
        vector<int> best(n + 1, INF);
        priority_queue<P, vector<P>, greater<P>> pq;

        best[1] = INF;            // 起点的瓶颈当作 +∞
        pq.push({best[1], 1});

        while (!pq.empty()) {
            auto [bu, u] = pq.top(); pq.pop();

            for (auto &[v, w] : g[u]) {
                int cand = min(bu, w);     
                if (cand < best[v]) {
                    best[v] = cand;
                    pq.push({cand, v});
                }
            }
        }
        return best[n];
    }
};