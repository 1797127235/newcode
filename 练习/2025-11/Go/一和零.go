package main

func findMaxForm(strs []string, m int, n int) int {
    length := len(strs)
	zero := make([]int, length + 1)

	for i := 1; i <= length; i++ {
		cnt0 := 0
		for _, ch := range strs[i-1] {
			if ch == '0'{
				cnt0++
			}
		}
		zero[i] = cnt0
	}

	dp := make([][]int,m + 1)

	for i := 0; i <= m; i++ {
		dp[i] = make([]int,n + 1)
	}

	dp[0][0] = 0

	for i := 1; i <= length; i++{
		cnt0 := zero[i]
		cnt1 := len(strs[i-1]) - cnt0

		for j:= m; j >=0; j--{
			for k:=n; k>=0; k--{
				if j >= cnt0 && k >= cnt1{
					dp[j][k] = max(dp[j][k],dp[j - cnt0][k - cnt1] + 1)
				}
			}
		}
	}

	return dp[m][n]
}