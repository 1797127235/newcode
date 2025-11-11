package main

import "math"

func minMalwareSpread1(graph [][]int, initial []int) int {
	n := len(graph)	
	g := make([][]int, n)
	for i := 0; i < n; i++{
		for j := 0; j < n; j++{
			if graph[i][j] == 1 && i != j{
				g[i] = append(g[i], j)
				g[j] = append(g[j], i)
			}
		}
	}

	anscnt := math.MaxInt32
	ans := -1

	for i := 0; i < len(initial); i++{
		vis := make([]int, n)
		cnt := 0
		q := make([]int,0)

		for j:=0; j < len(initial); j++{
			if j == i{
				continue
			}
			vis[initial[j]] = 1
			q = append(q, initial[j])
		}

		for len(q) > 0{
			u := q[0]
			q = q[1:]
			cnt++
			for _, v := range g[u]{
				if vis[v] == 0{
					vis[v] = 1
					q = append(q, v)
				}
			}
		}
		if cnt < anscnt{
			anscnt = cnt
			ans = initial[i]
		}
		if cnt == anscnt{
			if ans == -1 || initial[i] < ans{
				ans = initial[i]
			}
		}
	}
	return ans
}


func minMalwareSpread(graph [][]int, initial []int) int {
	n := len(graph)
	anscnt := 0
	ans := -1

	//找只包含一个感染点的连通块
	mp := make(map[int]int)
	for _, v := range initial {
		mp[v] = 1
	}
	g := make([][]int, n)
    
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if graph[i][j] == 1 && i != j {
				g[i] = append(g[i], j)
				g[j] = append(g[j], i)
			}
		}
	}
	
	cnt := 0
	flag := false
	var dfs func(u int, start int,vis []int) 
	dfs = func(u int,start int, vis []int)  {
		if flag {
			return 
		}
		vis[u] = 1
		cnt++
		for _, v := range g[u] {
			if mp[v] == 1 && v != start {
				flag = true
				return 
			}

			if vis[v] == 0 {
				dfs(v,start,vis)
			}
		}
	}

	for i := 0; i < len(initial); i++ {
		vis := make([]int, n)
		cnt = 0
		flag = false
		dfs(initial[i],initial[i], vis)
		
		if flag {
			continue
		}
		if cnt > anscnt {
			anscnt = cnt
			ans = initial[i]
		}
		if cnt == anscnt {
			if ans == -1 || initial[i] < ans {
				ans = initial[i]
			}
		}
	}

	return ans

}