package main


func minOperations(nums []int) int {
	st := make([]int,0)
	ans := 0
	for i:=0;i<len(nums);i++{
		for len(st) > 0 && nums[i] < nums[st[len(st)-1]]{
			st = st[:len(st)-1]
			ans+=1
		}
		if len(st) > 0 && nums[i] == nums[st[len(st)-1]]{
			continue
		}

		st = append(st,i)
	}
	if nums[st[0]] == 0{
		ans -= 1
	}

	ans = ans + len(st)
	return ans
}