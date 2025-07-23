/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        /*
         * Problem: 0203 - Remove Linked List Elements
         * Given head of linked list and value val, remove all nodes with Node.val == val
         * and return the new head.
         * 
         * Approach: Use dummy node to handle edge cases. Traverse list with prev and
         * current pointers. When current.val == val, skip the node by updating prev.next.
         * 
         * Time complexity: O(n) where n is number of nodes.
         * Space complexity: O(1).
         */
        
        // Create dummy node to handle edge case where head needs to be removed.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;
        
        // Traverse the linked list.
        while (current) {
            if (current->val == val) {
                // Skip the current node by updating prev->next.
                prev->next = current->next;
            } else {
                // Move prev pointer only when we don't remove current node.
                prev = current;
            }
            
            // Always move current pointer to next node.
            current = current->next;
        }
        
        // Return the new head (dummy->next handles all edge cases).
        ListNode* newHead = dummy->next;
        delete dummy;  // Clean up dummy node to avoid memory leak.
        return newHead;
    }
};
