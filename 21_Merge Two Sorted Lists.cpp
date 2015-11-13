/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
        ListNode *origin = result;
        if (!l1 && !l2) {
            return NULL;
        }
        while (l1 && l2) {
            if (l1->val < l2->val) {
                result->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                result->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            result = result->next;
        }
        if (!l1 && !l2) {
            return origin->next;
        } else {
            result->next = l1?l1:l2;
            return origin->next;
        }
    }
};