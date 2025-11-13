package main

// type ListNode struct {
// 	Val  int
// 	Next *ListNode
// }

func removeNthFromEnd(head *ListNode, n int) *ListNode {
    left := head
	right := head
	for i := 0; i < n; i++ {
		right = right.Next
	}

	for right.Next != nil {
		left = left.Next
		right = right.Next
	}

	lnx := left.Next

	left.Next = lnx.Next

	return head
}