//https://leetcode.cn/problems/add-two-numbers/?envType=study-plan-v2&envId=top-100-liked



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int nx = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(l1 && l2)
        {
            int sum = l1->val + l2->val + nx;
            nx = sum /10;
            int cur = sum % 10;
            tail->next = new ListNode(cur);
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            int sum = l1->val + nx;
            nx = sum /10;
            int cur = sum % 10;
            tail->next = new ListNode(cur);
            tail = tail->next;
            l1 = l1->next;
        }
        while(l2)
        {
            int sum = l2->val + nx;
            nx = sum /10;
            int cur = sum % 10;
            tail->next = new ListNode(cur);
            tail = tail->next;
            l2 = l2->next;
        }
        if(nx)
        {
            tail->next = new ListNode(nx);
            tail = tail->next;
        }
        return dummy->next;
    }
};