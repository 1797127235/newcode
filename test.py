# Definition for singly-linked list.
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        cnt = 0
        node = head
        while node:
            cnt += 1
            node = node.next

        dummy = ListNode(next=head)

        p0 = dummy
        
        while cnt >= k:
            cnt -= k
            pre = None
            cur = p0.next
            for _ in range(k):
                nxt = cur.next
                cur.next = pre
                pre = cur
                cur = nxt
            
            nxt = p0.next   
            p0.next.next = cur
            p0.next = pre
            p0 = nxt

        return dummy.next
