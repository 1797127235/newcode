package main

import "math"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minCostClimbingStairs(cost []int) int {
	n := len(cost)
	memo := make([]int, n+1)
	for i := range memo {
		memo[i] = -1
	}
	var dfs func(u int) int
	dfs = func(u int) int {
		if u >= n {
			return math.MaxInt32
		}
		if memo[u] != -1 {
			return memo[u]
		}
		res := math.MaxInt32
		res = min(res, dfs(u+1)+cost[u])
		if u+2 <= n {
			res = min(res, dfs(u+2)+cost[u])
		}
		memo[u] = res
		return res
	}
	return min(dfs(0), dfs(1))
}
