package main

/*
#cgo CXXFLAGS: -std=c++11
*/
import "C"
import (
    "fmt"
    "sort"
)
// 统计 target 为多数元素的子数组个数
func countMajoritySubarrays(nums []int, target int) int64 {
    n := len(nums)

    // 1. 映射：target -> 1，其他 -> -1
    a := make([]int, n)
    for i, x := range nums {
        if x == target {
            a[i] = 1
        } else {
            a[i] = -1
        }
    }

    // 2. 前缀和 p[0..n]
    pref := make([]int, n+1)
    s := 0
    pref[0] = 0
    for i := 0; i < n; i++ {
        s += a[i]
        pref[i+1] = s
    }

    // 3. 离散化前缀和
    comp := make([]int, n+1)
    copy(comp, pref)
    sort.Ints(comp)

    // 去重
    m := 0
    for _, v := range comp {
        if m == 0 || v != comp[m-1] {
            comp[m] = v
            m++
        }
    }
    comp = comp[:m]

    // 值 -> 排名 (1-based)
    idxMap := make(map[int]int, m)
    for i, v := range comp {
        idxMap[v] = i + 1
    }

    // 4. 树状数组
    bit := make([]int64, m+2)

    add := func(i int, delta int64) {
        for i <= m {
            bit[i] += delta
            i += i & -i
        }
    }

    sum := func(i int) int64 {
        var res int64
        for i > 0 {
            res += bit[i]
            i -= i & -i
        }
        return res
    }

    // 遍历所有前缀和：统计之前有多少个 < 当前值
    var ans int64
    for _, v := range pref {
        r := idxMap[v]      // 当前前缀和的排名
        ans += sum(r - 1)   // 所有排名 < r 的数量
        add(r, 1)           // 把当前前缀和加入
    }

    return ans
}

func main() {
    nums := []int{1, 2, 2, 3}
    target := 2
    fmt.Println(countMajoritySubarrays(nums, target)) // 输出 5
}
