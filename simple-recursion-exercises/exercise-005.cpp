/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Reverse a singly linked list.
// A linked list can be reversed either iteratively or recursively. Could you implement both?
//Input: 1->2->3->4->5->NULL
//Output: 5->4->3->2->1->NULL

class Solution {
public:
    ListNode* point(ListNode* a, ListNode* b, ListNode*c) {
        b->next = a;
        if (c==NULL) { return b; }
        return point(b, c, c->next);
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL) { return NULL; }
        return point(NULL, head, head->next);
    }
};
