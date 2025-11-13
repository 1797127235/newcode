package main

func detectCycle(head *ListNode) *ListNode {
	slow := head
	fast := head

	for fast != nil && fast.Next != nil && slow != fast {
		slow = slow.Next
		fast = fast.Next.Next
	}

	for slow != head{
		slow = slow.Next
		head = head.Next
	}
	return head
}