package main

func bitlength(n int)int{
	length := 0
	for n > 0{
		n = n >> 1
		length++
	}
	return length
}

func minimumOneBitOperations(n int) int {
    if n <= 1{
		return n
	}
	cnt := bitlength(n)

	return (1 << cnt) - 1 - minimumOneBitOperations(n - (1 << (cnt - 1)))
}