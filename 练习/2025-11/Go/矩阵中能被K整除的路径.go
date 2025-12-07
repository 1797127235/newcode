package main

func numberOfPaths(grid [][]int, k int) int {
    m,n := len(grid),len(grid[0])
	mod := int(1e9 + 7)

	dp := make([][][]int,m + 1)

	for i:= 0; i <= m; i++{
		dp[i] = make([][]int,n + 1)
		for j:=0; j <= n;j++{
			dp[i][j] = make([]int,k + 1)
		}
	}


	dp[1][1][grid[0][0] % k] = 1

	for i:=1; i <= m; i++{
		for j:=1; j <= n; j++{
			for r:=0; r < k; r++{
				x:= (grid[i - 1][j - 1]) % k
				//不能这么写
				/*
					模运算是循环的，即使当前格子的值很大，加上前面的路径和之后，总和余k可能很小
				*/
				// if x > r{
				// 	continue
				// }
				//此时要凑成%k余数为r
				dp[i][j][r] = (dp[i][j][r] + dp[i - 1][j][(r - x + k) %k]) %mod;
				dp[i][j][r] = (dp[i][j][r] + dp[i][j - 1][(r - x + k) %k]) %mod;
			}
		}
	}

	return dp[m][n][0]
}