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
        
        ListNode* current_node = head;
        vector<ListNode*> my_nodes;
        
        while (current_node != NULL) {
            my_nodes.push_back(current_node);
            current_node = current_node->next;
        }

        
        int current = my_nodes.size() - n ;
        
        if (current == 0) {
            return head->next;
        }
                
        my_nodes[current - 1]->next = my_nodes[current]->next;
        return head;
    }
};
