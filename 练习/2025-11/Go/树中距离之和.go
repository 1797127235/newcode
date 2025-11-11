package main

func sumOfDistancesInTree(n int, edges [][]int) []int {
    sz := make([]int,n)
	ans := make([]int,n)
	g := make([][]int,n)
	for _,e := range edges {
		u,v := e[0],e[1]
		g[u] = append(g[u],v)
		g[v] = append(g[v],u)
	}

	var dfs1 func(u int,fa int,deepth int)
	dfs1 = func(u int,fa int,deepth int) {
		ans[0] += deepth
		sz[u] = 1
		for _,v := range g[u] {
			if v == fa{
				continue
			}

			dfs1(v,u,deepth + 1)
			sz[u] += sz[v]
		}
	}

	dfs1(0,-1,0)

	var dfs2 func(u int,fa int)
	dfs2 = func(u int,fa int) {
		for _,v := range g[u] {
			if v == fa{
				continue
			}

			ans[v] = ans[u] - sz[v] + (n - sz[v])
			dfs2(v,u)
		}
	}

	dfs2(0,-1)

	return ans

}