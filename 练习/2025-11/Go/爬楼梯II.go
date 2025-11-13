package main

import "math"


func climbStairs(n int, costs []int) int {
	var dp func(u int) int
	dp = func(u int) int {
		if u == n - 1{
			return 0
		}

		res := math.MaxInt32

		for i := 1; i <= 3; i++{
			if u + i < n{
				res = min(res,costs[u - 1] + (u -1 ) * (u - 1))
			}
		}
		return res
	}
	return dp(0)
}