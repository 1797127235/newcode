package main

import (
	"bufio"
	"os"
	"fmt"
)

func main(){
	in := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(in, &n)
	g := make([][]int, n + 1)

	for i := 1; i <= n - 1; i++ {
		var u, v int
		fmt.Fscan(in, &u, &v)
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}

	

}