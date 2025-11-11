package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */


func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	lcnt := minDepth(root.Left)
	rcnt := minDepth(root.Right)

	return min(lcnt, rcnt) + 1
}