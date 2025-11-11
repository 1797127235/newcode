//https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/description/

package main

// /**
//  * Definition for a binary tree node.
//  * type TreeNode struct {
//  *     Val int
//  *     Left *TreeNode
//  *     Right *TreeNode
//  * }
//  */
type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}
func dfs(root *TreeNode) int {
	if root == nil {
		return 0
	}
	leftDepth := dfs(root.Left)
	rightDepth := dfs(root.Right)
	if leftDepth > rightDepth {
		return leftDepth + 1
	} else {
		return rightDepth + 1
	}
}
func calculateDepth(root *TreeNode) int {
	return dfs(root)
}