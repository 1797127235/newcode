package main

func maxOperations(s string) int {
    n := len(s)
	cnt := 0
	ans := 0
	for i := 0; i < n; i++{
		if s[i] == '1'{
			cnt += 1
		}else if i > 0 && s[i - 1] == '1'{
			ans += cnt
		}
	}

	return ans

}