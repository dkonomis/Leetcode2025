#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
        Problem: 0002 - Add Two Numbers.

        Given two linked lists representing non-negative integers in reverse order,
        return their sum as a new linked list.

        Approach:
        - Use a dummy node to simplify linked list construction.
        - Traverse both lists while adding digits and carry.
        - For each digit, create a new node and attach it.
        - Return dummy.next to skip the placeholder node.

        Time Complexity: O(max(n, m)), where n and m are the lengths of l1 and l2.
        Space Complexity: O(max(n, m)).
        */

        ListNode dummy(0);              // Dummy node simplifies edge handling.
        ListNode* current = &dummy;     // Pointer to build the result list.
        int carry = 0;                  // Carry from previous digit.

        while (l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int total = val1 + val2 + carry;
            carry = total / 10;
            int digit = total % 10;

            current->next = new ListNode(digit);  // Append new digit node.
            current = current->next;              // Move to new end of list.

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy.next;  // Return head of the new list, skipping dummy.
    }
};

