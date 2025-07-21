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
    ListNode *detectCycle(ListNode *head) {
        /*
        Problem: 0142 - Linked List Cycle II
        
        Find the node where cycle begins using extended Floyd's algorithm.
        
        Approach:
        1. Phase 1: Use Floyd's algorithm to detect cycle and find meeting point.
        2. Phase 2: Reset one pointer to head, move both at same speed until they meet.
        3. Meeting point in phase 2 is the cycle start (mathematical property).
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(1) using only constant extra space.
        */
        
        if (!head || !head->next) {
            return nullptr;
        }
        
        // Phase 1: Detect cycle using Floyd's algorithm.
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Find meeting point inside cycle.
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                break;
            }
        }
        
        // Check if cycle was found.
        if (!fast || !fast->next) {
            return nullptr;
        }
        
        // Phase 2: Find cycle start.
        // Reset one pointer to head, move both at same speed.
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Both pointers now point to cycle start.
        return slow;
    }
};
