#include <cstddef>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /*
    Problem: 0061 - Rotate List

    Given the head of a singly linked list, rotate the list to the right by k places.

    Approach:
    - First, compute the length of the list and get the tail node.
    - Normalize k by taking k modulo length (k %= length).
    - If k is zero, return head as is.
    - Otherwise, find the new tail at (length - k - 1)-th node.
    - The node after that becomes the new head.
    - Break the list at the new tail and reconnect the original tail to the old head.

    Time Complexity: O(n), where n is the number of nodes.
    Space Complexity: O(1), constant extra space.
    */
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;  // No rotation needed.
        }

        // Compute the length of the list and get the tail.
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            ++length;
        }

        k %= length;  // Normalize k to avoid full-cycle rotations.
        if (k == 0) {
            return head;  // No rotation needed.
        }

        // Find the new tail: (length - k - 1)-th node.
        ListNode* new_tail = head;
        for (int i = 0; i < length - k - 1; ++i) {
            new_tail = new_tail->next;
        }

        // The new head is the node after the new tail.
        ListNode* new_head = new_tail->next;

        // Break and reconnect.
        new_tail->next = nullptr;
        tail->next = head;

        return new_head;
    }
};

