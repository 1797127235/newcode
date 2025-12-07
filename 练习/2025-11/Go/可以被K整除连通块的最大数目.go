package main

func maxKDivisibleComponents(n int, edges [][]int, values []int, k int) int {
	g := make([][]int,n)
	for _,e := range edges{
		u,v := e[0],e[1]
		g[u] = append(g[u],v)
		g[v] = append(g[v],u)
	}
	ans := 0
	var dfs func(int,int)int
	dfs = func(u,fa int)int{
		sum := values[u]

		for _,v := range g[u]{
			if v == fa{
				continue
			}
			sum += dfs(v,u)
		}

		if sum % k == 0{
			ans++
			return 0
		}

		return sum
	}
	dfs(0,-1)
	return ans
}