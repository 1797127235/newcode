package main

import (
	"math"
)

func minSubarray(nums []int, p int) int {
	var sum int64  = 0
	for _,x := range(nums){
		sum += int64(x)
	}

	var target int64 = sum % int64(p)

	if target == 0{
		return 0
	}
	//找到最短子数组使得和模上p的余数是target
	var ans int = math.MaxInt32

	mp := make(map[int64]int64)
	mp[0] = -1
	var cur int64 = 0
	for r,x := range nums{
		if x == int(target){
			return 1
		}
		cur += int64(x)
		if val,has := mp[(cur - target + int64(p)) % int64(p)];has{

			ans = int(min(int64(ans),int64(r)-val))
		}

		mp[int64(cur%int64(p))] = int64(r)
	}
	if ans >= len(nums) {
		return -1
	}else{
		return ans
	}
}