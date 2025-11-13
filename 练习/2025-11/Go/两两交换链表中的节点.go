package main


type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
    if head == nil{
        return nil
    }
	if head.Next == nil || head.Next.Next == nil {
		//ListNode* ed = head.Next

		ed := head.Next
		ed.Next = head
		head.Next = nil

		return ed
	}

	newHead := head.Next

	head.Next = swapPairs(newHead.Next)

	newHead.Next = head

	return newHead
}