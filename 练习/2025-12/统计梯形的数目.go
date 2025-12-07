//https://leetcode.cn/problems/count-number-of-trapezoids-i/description/

package main

//ans += C(k,2) * cnt

// 一键切换类型：改成 int 或 int64 都可以
type FT int64

type FenwickTree struct {
	bit []FT
	n   int
}

// 初始化：传入数组大小 n
func NewFenwickTree(n int) *FenwickTree {
	return &FenwickTree{
		bit: make([]FT, n+1),
		n:   n,
	}
}

// 单点加：a[idx] += val
func (fw *FenwickTree) Update(idx int, val FT) {
	for idx <= fw.n {
		fw.bit[idx] += val
		idx += idx & -idx
	}
}

// 前缀和：sum[1..idx]
func (fw *FenwickTree) Query(idx int) FT {
	var res FT
	for idx > 0 {
		res += fw.bit[idx]
		idx -= idx & -idx
	}
	return res
}

// 区间和：sum[l..r]
func (fw *FenwickTree) RangeQuery(l, r int) FT {
	return fw.Query(r) - fw.Query(l-1)
}

// 用初始数组构建
func NewFenwickTreeFromArray(arr []FT) *FenwickTree {
	n := len(arr)
	fw := NewFenwickTree(n)
	for i := 1; i <= n; i++ {
		fw.Update(i, arr[i-1])
	}
	return fw
}

type Point struct {
	x int
	y int
}


func countTrapezoids(points [][]int) (ans int) {
	const mod = 1_000_000_007
	cnt := make(map[int]int, len(points)) // 预分配空间
	for _, p := range points {
		cnt[p[1]]++ // 统计每一行（水平线）有多少个点
	}

	s := 0
	for _, c := range cnt {
		k := c * (c - 1) / 2
		ans += s * k
		s += k
	}
	return ans % mod
}
