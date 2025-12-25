package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)
func main() {
	mod := 998244353
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	next := func() int {
		sc.Scan()
		val, _ := strconv.Atoi(sc.Text())
		return val
	}

	n := next()
	
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		nums[i] = next()
	}
	//恰好包含十个元素
	mp := make(map[int]int)

	for i := 0; i < n; i++ {
		mp[nums[i]]++
	}

	n2, n4 := 0, 0
	for _, c := range mp {
		if c >= 2 {
			n2++
		}
		if c >= 4 {
			n4++
		}
	}

	ans := 0

	//枚举较小的第一个数，看相邻
    for a, c1 := range mp {
		if c1 < 3 {
			continue
		}
        c2, ok := mp[a+1]

        if !ok || c2 < 3 {
            continue
        }

		//当前2 4 的数量
        curr1, curr2 := n2, n4

        if c1 >= 2 && c1-3 < 2 { curr1-- }
        if c1 >= 4 && c1-3 < 4 { curr2-- }

        if c2 >= 2 && c2-3 < 2 { curr1-- }
        if c2 >= 4 && c2-3 < 4 { curr2-- }
        // 计算当前 a 情况下的组合方案
        // C（cur1,2)
        ways := int64(curr1) * int64(curr1-1) / 2
        // C(curr2, 1)
        ways += int64(curr2)

        ans = (ans + int(ways % int64(mod))) % mod
    }

    fmt.Println(ans)
	


}