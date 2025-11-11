//https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<ll>> dist(n,vector<ll>(n,INT_MAX));

        for(auto &e : edges)
        {
            int from = e[0], to = e[1], dis = e[2];
            dist[from][to] = dis;
            dist[to][from] = dis;
        }
        for(int i = 0; i < n;i++) dist[i][i] = 0;

        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }

        int anscnt = INT_MAX;
        int ans = -1;

        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
                if(dist[i][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }

            if(cnt < anscnt)
            {
                anscnt = cnt;
                ans = i;
            }
            else if(cnt == anscnt)
            {
                ans = max(ans,i);
            }
        }
        return ans;
    }
};