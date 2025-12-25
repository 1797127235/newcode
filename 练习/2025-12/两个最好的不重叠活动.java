class Solution {
    public int maxTwoEvents(int[][] events) {
        int n = events.length;

        // 按结束时间排序
        Arrays.sort(events, (a, b) -> Integer.compare(a[1], b[1]));

        // best[i]：前 i 个活动中，只选 1 个活动的最大价值
        int[] best = new int[n];
        best[0] = events[0][2];

        for (int i = 1; i < n; i++) {
            best[i] = Math.max(best[i - 1], events[i][2]);
        }

        int ans = best[n - 1]; // 只选一个活动的情况

        // dp[i]：以第 i 个活动作为第二个活动
        for (int i = 0; i < n; i++) {
            int l = 0, r = i - 1;
            int p = -1;

            while(l < r) {
                int mid = (l + r + 1) >> 1;
                if(events[mid][1] < events[i][0]) {
    
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }

            if (events[l][1] < events[i][0]) p = l;
            int cur = events[i][2] + (p >= 0 ? best[p] : 0);
            ans = Math.max(ans, cur);
        }

        return ans;
    }
}


class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        int n = events.size();
        // 按结束时间排序
        sort(events.begin(), events.end(), [&](vector<int>& a, vector<int>& b)
        {
            return a[1] < b[1];
        });      
        
        vector<int> dp(n + 1); //init dp[0]
        
        for(int i = 1; i <= n; i++)
        {
            auto t = events[i - 1];
            
            // 找到结束时间 < t[0] 的位置
            auto it = lower_bound(events.begin(), events.begin() + i - 1, t[0],
                [](const vector<int>& event, int start) {
                    return event[1] < start;  // 结束时间 < 开始时间
                });
            
            int idx = it - events.begin();
            dp[i] = max(dp[i - 1], dp[idx] + t[2]);
        }
        return dp[n];
    }
};
