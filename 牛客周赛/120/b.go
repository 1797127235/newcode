package main

import (
	"bufio"
	"fmt"
	"os"
)

func calc(n, offset int64) int64 {
	if n < offset {
		return 0
	}
	return (n-offset)/3 + 1
}

func main() {
	in := bufio.NewReader(os.Stdin)
	var l, r int64
	fmt.Fscan(in, &l, &r)

	a := calc(r, 1) - calc(l-1, 1) 
	b := calc(r, 2) - calc(l-1, 2) 
	c := calc(r, 3) - calc(l-1, 3) 

	fmt.Println(a, b, c)
}
