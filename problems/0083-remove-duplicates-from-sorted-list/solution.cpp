class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        /*
        Problem: 0083 - Remove Duplicates from Sorted List

        Given the head of a sorted linked list, delete all duplicates so each element appears only once.

        Approach:
        - Traverse the list with a pointer.
        - If the current node has the same value as the next, skip the next node.
        - Otherwise, move to the next node.

        Time complexity: O(n), where n is the number of nodes.
        Space complexity: O(1).
        */
        ListNode* curr = head; // Start from the head.

        while (curr && curr->next) {
            // If current node and next node have the same value, skip the next node.
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
            } else {
                // Otherwise, move to the next node.
                curr = curr->next;
            }
        }

        return head;
    }
};

