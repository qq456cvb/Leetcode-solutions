class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ln = new ListNode(0);
        ListNode *orig = ln;
        bool add = false;
        while (l1 != nullptr && l2 != nullptr) {
            ln->next = new ListNode((l1->val + l2->val + (int)add) % 10);
            ln = ln->next;
            add = ((l1->val + l2->val + (int)add) >= 10);
            l1 = l1->next;
            l2 = l2->next;
        }
        if (!l1) {
            while (l2) {
                if (add) {
                    add = false;
                    ln->next = new ListNode((l2->val + 1) % 10);
                    if (l2->val + 1 >= 10) {
                        add = true;
                    }
                } else {
                    ln->next = new ListNode(l2->val);
                }
                ln = ln->next;
                l2 = l2->next;
            }
        }
        if (!l2) {
            while (l1) {
                if (add) {
                    add = false;
                    ln->next = new ListNode((l1->val + 1) % 10);
                    if (l1->val + 1 >= 10) {
                        add = true;
                    }
                } else {
                    ln->next = new ListNode(l1->val);
                }
                ln = ln->next;
                l1 = l1->next;
            }
        }
        if (add) {
            ln->next = new ListNode(1);
        }
        return orig->next;
    }
};