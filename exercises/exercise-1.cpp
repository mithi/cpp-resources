/**
Add two numbers

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) { return l2; }
        if (l2 == NULL) { return l1; }

        ListNode* sum = new ListNode(0);
        ListNode* s = sum;
        ListNode* x = l1;
        ListNode* y = l2;
        int carry = 0;

        while (1) {
            int p = x == NULL ? 0 : x->val;
            int q = y == NULL ? 0 : y->val;
            s->val = p + q + carry;

            if (s->val > 9) {
                s->val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            x = x == NULL ? NULL : x->next;
            y = y == NULL ? NULL : y->next;

            if (x == NULL && y == NULL && carry == 0) {
                break;
            }
            s->next = new ListNode(0);
            s = s->next;
        }
        return sum;
    }
};
