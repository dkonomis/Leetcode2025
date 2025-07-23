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
    ListNode* reverseList(ListNode* head) {
        /*
         * Problem: 0206 - Reverse Linked List
         * Given head of singly linked list, reverse the list and return the reversed list.
         * Reverse the direction of all pointers to flip the list.
         * 
         * Approach: Use three pointers (prev, current, next) to iteratively reverse
         * each link. Track previous node, current node, and next node to avoid losing references.
         * 
         * Time complexity: O(n) where n is number of nodes.
         * Space complexity: O(1).
         */
        
        ListNode* prev = nullptr;
        ListNode* current = head;
        
        // Iterate through the list and reverse each link.
        while (current) {
            // Store next node before breaking link.
            ListNode* next_node = current->next;
            // Reverse the link to point backwards.
            current->next = prev;
            // Move prev pointer forward.
            prev = current;
            // Move current pointer forward.
            current = next_node;
        }
        
        // prev now points to the new head of reversed list.
        return prev;
    }
};
