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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*
        Problem 0021 – Merge Two Sorted Lists.

        Given the heads of two sorted linked lists `list1` and `list2`,
        merge them into one sorted linked list and return the head.

        The merged list should be made by splicing together the nodes of the two lists.

        Approach:
        Use a dummy node to simplify edge-case handling.
        Traverse both lists in parallel, always attaching the smaller node to the tail
        of the merged result. Move forward in the list from which the node was taken.
        Once one list is exhausted, append the remaining part of the other list.

        Time Complexity  : O(m + n), where m and n are the lengths of the input lists.
        Space Complexity : O(1), not counting the output list which is built in-place.
        */

        ListNode dummy(0);
        ListNode* current = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        current->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;
    }
};

