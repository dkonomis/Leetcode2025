class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        /*
        Problem: 0086 - Partition List

        Given the head of a linked list and an integer x, rearrange the list such that:
        - All nodes with values less than x come before nodes with values ≥ x.
        - The relative order of nodes in each partition is preserved.

        Approach:
        - Use two dummy nodes to build two lists:
            - One for nodes less than x.
            - One for nodes greater than or equal to x.
        - Traverse the list once, attaching nodes to the appropriate partition.
        - Connect the end of the <x list to the head of the ≥x list.
        - Return the new head (dummy1.next).

        Time complexity: O(n), where n is the number of nodes.
        Space complexity: O(1), only pointer manipulation.
        */

        ListNode* dummy1 = new ListNode(0);  // Dummy head for <x partition.
        ListNode* dummy2 = new ListNode(0);  // Dummy head for ≥x partition.

        ListNode* tail1 = dummy1;  // Tail for <x list.
        ListNode* tail2 = dummy2;  // Tail for ≥x list.

        while (head) {
            if (head->val < x) {
                tail1->next = head;  // Append to <x list.
                tail1 = tail1->next;
            } else {
                tail2->next = head;  // Append to ≥x list.
                tail2 = tail2->next;
            }
            head = head->next;
        }

        tail2->next = nullptr;         // Terminate the ≥x list.
        tail1->next = dummy2->next;    // Connect the two partitions.

        return dummy1->next;
    }
};

