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
    bool hasCycle(ListNode *head) {
        /*
        Problem: 0141 - Linked List Cycle
        
        Detect if linked list has a cycle using Floyd's algorithm.
        
        Approach:
        1. Use two pointers: slow (1 step) and fast (2 steps).
        2. If there's a cycle, fast will eventually catch up to slow.
        3. If no cycle, fast will reach the end (nullptr).
        4. Floyd's Tortoise and Hare algorithm.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(1) using only constant extra space.
        */
        
        if (!head || !head->next) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Move pointers until they meet or fast reaches end.
        while (fast && fast->next) {
            slow = slow->next;        // Tortoise: 1 step.
            fast = fast->next->next;  // Hare: 2 steps.
            
            // If pointers meet, there's a cycle.
            if (slow == fast) {
                return true;
            }
        }
        
        // Fast reached end, no cycle.
        return false;
    }
};
