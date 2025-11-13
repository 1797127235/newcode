//https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-100-liked

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    先计算链表总长
    删除倒数第n个节点 = 删除正数第(len - n + 1)个节点
*/
int count(ListNode* head)
{
    if(!head) return 0;

    return 1 + count(head->next);
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        cnt = count(head);

        //删除正数第cnt个
        cnt = cnt -n + 1;
        //走cnt - 2 步
        ListNode* tail = head;

        //走 cnt - 2 步
        if(cnt == 1)
        {
            return head->next;
        }
        else
        {
            for(int i = 0; i < cnt - 2; i++)
            {
                tail = tail->next;
            }
            //删除tail的下一个节点
            ListNode* del = tail->next;
            tail->next = tail->next->next;
            delete del;
            return head;
        }
    }
};