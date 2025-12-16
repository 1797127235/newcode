//https://leetcode.cn/problems/count-special-triplets/

package main

func specialTriplets(nums []int) int {
    n := len(nums)
    mod := int(1e9 + 7)
    suf := make(map[int]int)
    for _, v := range nums {
        suf[v]++
    }
    pre := make(map[int]int)
    res := 0
    for i := 0; i < n; i++ {
        suf[nums[i]]--
        res = (res + pre[nums[i] *2] * suf[nums[i] *2] % mod ) % mod
        pre[nums[i]]++
    }

    return res
}