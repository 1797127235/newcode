package main
import "math"
func climbStairs(n int, costs []int) int {
	dp := make([]int, n + 1)
	dp[0] = 0
	for i := 1; i <= n; i++{
		dp[i] = math.MaxInt32
	}
	for i := 1; i <= n; i++{
		for j := 1; j <= 3; j++{
			ed := j - i
			if ed >= 1{
				dp[i] = min(dp[i],dp[ed] + costs[ed - 1] + (ed - i) * (ed - i))
			}
		}
	}

	return dp[n]
}