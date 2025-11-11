package main

import "math/bits"

// func minimizeXor(num1 int, num2 int) int {
//     cnt2 := 0
// 	cnt1 := 0
// 	ans := 0
// 	for num2 > 0{
// 		if num2&1 == 1 {
// 			cnt2++
// 		}
// 		num2 >>= 1
// 	}
// 	t := num1
// 	for t > 0{
// 		if t&1 == 1 {
// 			cnt1++
// 		}
// 		t >>= 1
// 	}

// 	if cnt1 == cnt2{
// 		return num1
// 	}else if cnt1 > cnt2{
// 		for i := 31; i >=0 && cnt2 > 0;i--{
// 			if (num1&(1<<i)) !=0{
// 				cnt2--
// 				ans = ans | (1 << i)
// 			}
// 		}
// 	}else{
// 		ans = num1
// 		cnt2 -= cnt1
// 		for i :=0; i <=31 && cnt2 > 0;i++{
// 			if (num1&(1<<i)) ==0{
// 				cnt2--
// 				ans = ans | (1 << i)
// 			}
// 		}
// 	}

// 	return ans
// }

/*
	记c1为num1中1的个数，c2为num2中1的个数
	当c1 == c2时，直接返回num1
	当c1 > c2时， 最低的1变成0，直到c1 == c2
	当c1 < c2时， 最低的0变成1，直到c1 == c2
	最后返回修改后的num1即可
*/
func minimizeXor(num1, num2 int) int {
	c1 := bits.OnesCount(uint(num1))
	c2 := bits.OnesCount(uint(num2))
	for ; c2 < c1; c2++ {
		num1 &= num1 - 1 // 最低的 1 变成 0
	}
	for ; c2 > c1; c2-- {
		num1 |= num1 + 1 // 最低的 0 变成 1
	}
	return num1
}
