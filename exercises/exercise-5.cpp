/**
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

 **/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL && n == 1) {
            return NULL;
        }
        
        ListNode* current = head;
        ListNode* previous = NULL;
        ListNode* last = head;
        int counter = 0;
        
        while(counter < n) {
            last = last->next;
            counter++;
        }
        
        if(last == NULL) {
            return head->next;
        }
        
        while(last != NULL) {
            last = last->next;
            previous = current;
            current = current->next;
        }
        
        previous->next = current->next; 
        return head;
    }
};
