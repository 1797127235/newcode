package main


func maximumDetonation(bombs [][]int) int {
    n := len(bombs)
	type Edge struct {
		to int
		dist int64
	}
	g := make([][]Edge, n)

	for i := 0; i < n;i++{
		for j := i + 1; j < n; j++{
			dx := int64(bombs[i][0] - bombs[j][0])
			dy := int64(bombs[i][1] - bombs[j][1])
			dist := dx * dx + dy * dy

			g[i] = append(g[i],Edge{to:j, dist:dist})
			g[j] = append(g[j],Edge{to:i, dist:dist})
		}
	}

	ans := 1
	vis := make([]bool, n)
	cnt := 0
	var dfs func(u int)
	dfs = func(u int){
		vis[u] = true
		cnt++
		ru := int64(bombs[u][2])
		r2 := ru * ru
		for _, e := range g[u]{
			if vis[e.to]{
				continue
			}
			if e.dist <= r2{
				dfs(e.to)
			}
		}
	}
	for i := 0; i < n; i++{
		cnt = 0
		for j := 0; j < n; j++{
			vis[j] = false
		}
		dfs(i)
		if cnt > ans{
			ans = cnt
		}
	}
	return ans
}