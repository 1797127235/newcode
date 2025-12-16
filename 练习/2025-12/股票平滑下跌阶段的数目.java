class Solution {
    public long getDescentPeriods(int[] prices) {
        int n = prices.length;
        long ans = n;
        long dp[] = new long[n];
        for(int i = 1; i < n; i++)
        {
            if(prices[i] + 1 == prices[i - 1])
            {
                dp[i] += dp[i - 1] + 1;
                ans += dp[i];
            }
        }
        return ans;
    }
}