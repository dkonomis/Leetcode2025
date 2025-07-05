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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        Problem 0019 – Remove Nth Node From End of List.

        Use two pointers: first and second.
        First advances n + 1 steps ahead to create a gap of n nodes.
        Then both pointers move together until first reaches the end.
        At that point, second points to the node before the one to delete.

        Time Complexity  : O(L), where L is the number of nodes in the list.
        Space Complexity : O(1).
        */

        // Create a dummy node before the head for easier deletion logic.
        ListNode* dummy = new ListNode(0, head);

        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move `first` ahead by n + 1 steps.
        for (int i = 0; i < n + 1; ++i) {
            first = first->next;
        }

        // Move both pointers until `first` reaches the end.
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Delete the nth node from the end.
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;

        delete nodeToDelete;  // Free memory.

        return dummy->next;
    }
};

