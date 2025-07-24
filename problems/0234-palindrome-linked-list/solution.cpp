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
    bool isPalindrome(ListNode* head) {
        /*
         * Problem: 0234 - Palindrome Linked List
         * 
         * Check if linked list is palindrome using O(1) space.
         * Find middle using fast/slow pointers, reverse second half, compare.
         * 
         * Time complexity: O(n) where n is the number of nodes.
         * Space complexity: O(1).
         */
        
        if (!head || !head->next) {
            return true;
        }
        
        // Find middle of the list using fast and slow pointers.
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the list.
        ListNode* second_half = reverseList(slow->next);
        
        // Compare first half with reversed second half.
        ListNode* first_half = head;
        while (second_half) {
            if (first_half->val != second_half->val) {
                return false;
            }
            first_half = first_half->next;
            second_half = second_half->next;
        }
        
        return true;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        // Reverse a linked list and return new head.
        ListNode* prev = nullptr;
        ListNode* current = head;
        
        while (current) {
            // Save next node.
            ListNode* next_temp = current->next;
            // Reverse the link.
            current->next = prev;
            // Move pointers forward.
            prev = current;
            current = next_temp;
        }
        
        return prev;
    }
};
