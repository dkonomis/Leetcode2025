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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /**
         * Problem: 0160 - Intersection of Two Linked Lists
         * 
         * Find the node where two linked lists intersect.
         * 
         * Approach:
         * Two pointers traverse both lists. When a pointer reaches the end,
         * redirect it to the head of the other list. They'll meet at intersection
         * or both become nullptr if no intersection.
         * 
         * Why it works: Each pointer travels distance a + c + b, where:
         * - a = length of A before intersection
         * - b = length of B before intersection  
         * - c = length of common part
         * 
         * Time complexity: O(m + n).
         * Space complexity: O(1).
         */
        
        if (!headA || !headB) {
            return nullptr;
        }
        
        // Initialize two pointers.
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        
        // Traverse until pointers meet.
        while (ptrA != ptrB) {
            // Move to next node or switch to other list's head.
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }
        
        // Either both are nullptr (no intersection) or both point to intersection.
        return ptrA;
    }
};
