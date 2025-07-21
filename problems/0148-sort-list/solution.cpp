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
    ListNode* sortList(ListNode* head) {
        /**
         * Problem: 0148 - Sort List
         * 
         * Sort a linked list in ascending order using merge sort.
         * 
         * Approach:
         * Use merge sort (divide and conquer):
         * 1. Split list in half using slow/fast pointers
         * 2. Recursively sort both halves
         * 3. Merge the sorted halves
         * 
         * Time complexity: O(n log n).
         * Space complexity: O(log n) for recursion stack.
         */
        
        if (!head || !head->next) {
            return head;
        }
        
        // Find the middle using slow/fast pointers.
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;  // Need to cut the list in half.
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Cut the list into two halves.
        prev->next = nullptr;
        
        // Recursively sort both halves.
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        // Merge the sorted halves.
        return merge(left, right);
    }
    
private:
    ListNode* merge(ListNode* left, ListNode* right) {
        /**Merge two sorted linked lists.**/
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        // Merge nodes in sorted order.
        while (left && right) {
            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        
        // Attach remaining nodes.
        if (left) {
            curr->next = left;
        }
        if (right) {
            curr->next = right;
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
