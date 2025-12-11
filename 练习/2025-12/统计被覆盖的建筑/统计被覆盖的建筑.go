package main

func countCoveredBuildings(n int, buildings [][]int) int {
    row_min := make(map[int]int)
	row_max := make(map[int]int)
	col_min := make(map[int]int)
	col_max := make(map[int]int)

	for _, building := range buildings {
		x,y := building[0], building[1]
		if val, exist := row_min[x]; !exist || y < val {
			row_min[x] = y
		}
		if val,exist := row_max[x]; !exist || y > val {
			row_max[x] = y
		}
		if val, exist := col_min[y]; !exist || x < val {
			col_min[y] = x
		}
		if val, exist := col_max[y]; !exist || x > val {
			col_max[y] = x
		}
	}

	ans := 0
	for _, building := range buildings {
		x,y := building[0], building[1]
		var f1 bool = (x > col_min[y] && x < col_max[y])
		var f2 bool = (y > row_min[x] && y < row_max[x])
		if f1 && f2 {
			ans++
		}
	}
	return ans
	
}