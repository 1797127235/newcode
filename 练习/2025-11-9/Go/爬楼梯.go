package main

func climbStairs(n int) int {
	memo := make([]int, n+1)
	for i := range memo {
		memo[i] = -1
	}
	var dfs func(u int) int
	dfs = func(u int) int {
		if u <= 0 {
			if u == 0 {
				return 1
			} else {
				return 0
			}
		}
		if memo[u] != -1 {
			return memo[u]
		}
		memo[u] = dfs(u-1) + dfs(u-2)
		return memo[u]
	}
	return dfs(n)
}
