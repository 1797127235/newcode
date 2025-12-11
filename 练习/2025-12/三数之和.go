package main

import "sort"

func threeSum(nums []int) [][]int {
	n := len(nums)
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	var res [][]int
	for i:= 0; i < n; i++ {
		if i > 0 && nums[i] == nums[i - 1] {
			continue
		}
		l,r := i + 1, n - 1
		for l < r {
			if l > i + 1 && nums[l] == nums[l - 1] {
				l++
				continue
			}
			if r < n - 1 && nums[r] == nums[r + 1] {
				r--
				continue
			}
			sum := nums[i] + nums[l] + nums[r]
			if sum == 0 {
				res = append(res, []int{nums[i], nums[l], nums[r]})
				l++
				r--
			}else if sum < 0 {
				l++
			}else{
				r--
			}
		}
	}
	return res
}