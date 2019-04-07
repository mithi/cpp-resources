//Given a linked list, swap every two adjacent nodes
// and return its head.
// You may not modify the values in the list's nodes,
// only nodes itself may be changed.
// Given 1->2->3->4, you should return the list as 2->1->4->3.

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

    ListNode* swap_pair(ListNode* x) {
        if (x == NULL) { return NULL; }
        if (x->next == NULL) { return x; }

        ListNode* y = x->next;
        x->next = swap_pair(y->next);
        y->next = x;
        return y;
    }

    ListNode* swap_pair2(ListNode* x) {
        if (x == NULL) { return NULL; }
        if (x->next == NULL) { return x; }

        ListNode* y = x->next;
        ListNode* z = y->next;
        y->next = x;
        x->next = swap_pair2(z);
        return y;
    }
};
