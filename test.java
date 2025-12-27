/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        if(head == null || head.next == null) return;

        // 使用一个双端队列来存储节点
        Deque<ListNode> deque = new ArrayDeque<>();

        while(head != null) {
            deque.offerLast(head);
            head = head.next;
        } 

        // 重新连接节点
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        int i = 0;
        int j = deque.size() - 1;
        while(i <= j) {
            if(i == j) {
                current.next = deque.pollFirst();
                current = current.next;
                current.next = null;
                break;
            }else {
                current.next = deque.pollFirst();
                current = current.next;
                current.next = deque.pollLast();
                current = current.next;
                current.next = null;
                i++;
                j--;
            }
        }
        head = dummy.next;
    }
}