//https://leetcode.cn/problems/course-schedule/?envType=study-plan-v2&envId=top-100-liked

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses,0);
        
        for(auto& pre : prerequisites)
        {
            in[pre[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i)
        {
            if(in[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto& pre : prerequisites)
            {
                if(pre[1] == u)
                {
                    in[pre[0]]--;
                    if(in[pre[0]] == 0)
                    {
                        q.push(pre[0]);
                    }
                }
            }
        }

        bool flag = true;
        for(int i = 0; i < numCourses; ++i)
        {
            if(in[i] != 0)
            {
                flag = false;
                break;
            }
        }

        return flag;
    }
};