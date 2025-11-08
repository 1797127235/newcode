package main

/*
#cgo CXXFLAGS: -std=c++11
*/
import "C"

func maxPower(stations []int, r int, k int) int64 {
	n := len(stations)

	// 先用差分法得到每个位置的初始电量 power[i]
	power := make([]int64, n+1) // n+1 便于做差分右端点+1
	for i, val := range stations {
		l := i - r
		if l < 0 {
			l = 0
		}
		rr := i + r
		if rr >= n {
			rr = n - 1
		}
		power[l] += int64(val)
		power[rr+1] -= int64(val)
	}
	for i := 1; i < n; i++ {
		power[i] += power[i-1]
	}
	power = power[:n] // 只保留 0..n-1

	// 检查是否能把所有城市的电量都提升到 >= mid
	check := func(mid int64) bool {
		diff := make([]int64, n+1) // 差分数组，记录“新增电站”对后续窗口的影响
		sumD := int64(0)
		kk := int64(k)

		for i := 0; i < n; i++ {
			sumD += diff[i]
			cur := power[i] + sumD
			if cur < mid {
				need := mid - cur             // 当前位置还需要补多少
				if need > kk {                // 不够就失败
					return false
				}
				kk -= need
				sumD += need                  // 从 i 起生效
				end := i + r + r + 1          // 在 end 位置失效
				if end > n {
					end = n
				}
				diff[end] -= need
			}
		}
		return true
	}

	// 二分答案：最大化最小电量
	var left int64 = 0
	var right int64 = 1e18 // 注意是 int64 范围
	for left < right {
		mid := (left + right + 1) / 2
		if check(mid) {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return left
}
