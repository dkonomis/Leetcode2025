class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        /*
        Problem: 0092 - Reverse Linked List II

        Given the head of a singly linked list and two integers left and right,
        reverse the nodes between positions left and right (1-indexed), and return the modified list.

        Approach:
        - Use a dummy node to simplify handling edge cases (e.g., reversing from head).
        - Traverse to the node just before position 'left'.
        - Reverse the sublist between 'left' and 'right' using in-place pointer reversal.
        - Reconnect the reversed sublist back into the main list by adjusting next pointers.

        Time complexity: O(n)
        Space complexity: O(1)
        */
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Traverse to the node just before position 'left'.
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // Reverse the sublist between left and right.
        ListNode* reverse_prev = prev;
        ListNode* current = prev->next;
        prev = nullptr;

        // Perform in-place reversal of the sublist.
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        // Reconnect the reversed sublist.
        reverse_prev->next->next = current;
        reverse_prev->next = prev;

        return dummy->next;
    }
};

