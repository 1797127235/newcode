package main

type ListNode struct {
	Val int
	Next *ListNode
}
func reverseList(head *ListNode) *ListNode {
	var prev *ListNode = nil
	var cur *ListNode = head
	for cur != nil {
		nxt := cur.Next
		cur.Next = prev
		prev = cur
		cur = nxt
	}
	return prev
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
    var dummy ListNode = ListNode{Next: head}
	p0 := &dummy
	for i := 1; i < left; i++ {
		p0 = p0.Next
	}
	prev := p0
	cur := p0.Next
	for i := 0; i < right - left + 1; i++ {
		nxt := cur.Next
		cur.Next = prev
		prev = cur
		cur = nxt
	}
	p0.Next.Next = cur
	p0.Next = prev
	return dummy.Next
}


func reverseKGroup(head *ListNode, k int) *ListNode {
    cnt := 0
	var p *ListNode = head
	for p != nil {
		cnt++
		p = p.Next
	}

	var dummy ListNode = ListNode{Next: head}
	p0 := &dummy
	for cnt >= k {
		cnt -= k
		var prev *ListNode = nil
		cur := p0.Next
		//k个反转
		for i := 0; i < k ; i++ {
			nxt := cur.Next
			cur.Next = prev
			prev = cur
			cur = nxt
		}
		next := p0.Next
		p0.Next.Next = cur
		p0.Next = prev
		p0 = next
	}
	return dummy.Next
}