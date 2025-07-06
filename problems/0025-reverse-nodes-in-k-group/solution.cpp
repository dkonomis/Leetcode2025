#include <cstddef>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*
        0025. Reverse Nodes in k-Group

        Problem:
        Given the head of a linked list, reverse the nodes of the list k at a time,
        and return the modified list. If the number of nodes is not a multiple of k,
        the remaining nodes at the end should remain as is. Do not modify node values.

        Approach:
        Use a dummy node before head to handle edge cases.
        For each group:
            - Check whether there are k nodes ahead.
            - If so, reverse them in-place by changing next pointers.
            - Reconnect the reversed group back into the list.
        Proceed group by group.

        Time Complexity: O(n), where n is the number of nodes.
        Space Complexity: O(1), constant extra space.
        */

        // Create a dummy node that points to the head.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* group_prev = dummy;

        while (true) {
            // Find the kth node from group_prev.
            ListNode* kth = group_prev;
            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }
            if (kth == nullptr) {
                break;  // Fewer than k nodes remaining.
            }

            ListNode* group_next = kth->next;

            // Reverse the k nodes.
            ListNode* prev = group_next;
            ListNode* curr = group_prev->next;

            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect previous group to the new head.
            ListNode* temp = group_prev->next;
            group_prev->next = kth;
            group_prev = temp;
        }

        return dummy->next;
    }
};

