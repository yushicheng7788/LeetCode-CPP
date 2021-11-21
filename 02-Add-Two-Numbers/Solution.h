class Solution {
public:
    // Simulate
    // Using dummy head
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(-1), *pre = dummyHead;
        
        int t = 0;    // t means carry flag
        while (l1 && l2) {
            int sum = 0;
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            sum += val1 + val2 + t;
            pre->next = new ListNode(sum % 10);
            t = sum / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            pre = pre->next;
        }
        if (t)
            pre->next = new ListNode(1);
        return dummyHead->next;
    }

    // recursion
    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
        return addTwoNumbers(l1, l2, 0);
    }

private:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int t) {
        if (!l1 && !l2)
            return t ? new ListNode(1) : nullptr;
        int val1 = l1 ? l1->val : 0, val2 = l2 ? l2->val : 0;
        return new ListNode((t + val1 + val2) % 10, addTwoNumbers(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, t / 10));
    }
};
