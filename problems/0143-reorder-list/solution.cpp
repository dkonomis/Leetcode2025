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
    void reorderList(ListNode* head) {
        /**
         * Problem: 0143 - Reorder List
         * 
         * Given a linked list L0 → L1 → ... → L(n-1) → Ln,
         * reorder it to: L0 → Ln → L1 → L(n-1) → L2 → L(n-2) → ...
         * 
         * Approach:
         * 1. Find the middle of the linked list using slow/fast pointers.
         * 2. Reverse the second half of the list.
         * 3. Merge the two halves by alternating nodes.
         * 
         * Time complexity: O(n).
         * Space complexity: O(1).
         */
        
        if (!head || !head->next) {
            return;
        }
        
        // Find the middle of the linked list.
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split the list into two halves.
        ListNode* second_half = slow->next;
        slow->next = nullptr;
        
        // Reverse the second half.
        ListNode* prev = nullptr;
        ListNode* curr = second_half;
        while (curr) {
            // Store next node before we change the pointer.
            ListNode* next_temp = curr->next;
            // Reverse the current node's pointer.
            curr->next = prev;
            // Move prev and curr one step forward.
            prev = curr;
            curr = next_temp;
        }
        
        // Merge the two halves by alternating nodes.
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            // Save next pointers.
            ListNode* first_next = first->next;
            ListNode* second_next = second->next;
            
            // Reorder connections.
            first->next = second;
            second->next = first_next;
            
            // Move to next pair.
            first = first_next;
            second = second_next;
        }
    }
};
