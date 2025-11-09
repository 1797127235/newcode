//https://leetcode.cn/problems/palindrome-number/
package main

func isPalindrome(x int) bool {
	if x < 0{
		return false
	}
	t := x

	num := 0
	for x > 0 {
		num = num * 10 + x % 10
		x /= 10
	}
	if num == t{
		return true
	}

	return false
}