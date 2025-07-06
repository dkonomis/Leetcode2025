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
    ListNode* swapPairs(ListNode* head) {
        /*
        0024. Swap Nodes in Pairs

        Problem:
        Given a linked list, swap every two adjacent nodes and return its head.
        You must solve the problem without modifying node values, only pointers.

        Approach:
        Use a dummy node before the head to simplify edge cases.
        Iterate through the list in pairs. At each step, swap the two adjacent nodes
        by reassigning pointers. Then move the traversal pointer forward by two nodes.

        Time Complexity: O(n), where n is the number of nodes.
        Space Complexity: O(1), constant extra space.
        */

        // Create a dummy node that points to the head.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Traverse the list in pairs.
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap the nodes by reassigning pointers.
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move to the next pair.
            prev = first;
        }

        return dummy->next;
    }
};

