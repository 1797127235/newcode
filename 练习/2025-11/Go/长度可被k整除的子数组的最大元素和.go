package main


func maxSubarraySum(nums []int, k int) int64 {
	n := len(nums)
	sum := make([]int64, n+1)
	for i := 1; i <= n; i++ {
		sum[i] = sum[i-1] + int64(nums[i-1])
	}
	
	var ans int64 = sum[k]
	used := make(map[int]int64)
	used[0] = 0
	for i := 1; i <= k; i++{
		if val, ok := used[i % k]; ok {
			used[i % k] = min(val, sum[i])
		} else{
			used[i % k] = sum[i]
		}
	}

	for i := k + 1; i <= n; i++ {
		mod := i % k
		if val, ok := used[mod]; ok {
			ans = max(ans, sum[i]-val)
			used[mod] = min(used[mod], sum[i])
		} else{
			used[mod] = sum[i]
		}
	}
	return ans
}