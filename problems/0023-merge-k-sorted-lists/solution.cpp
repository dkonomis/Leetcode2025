#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
        0023. Merge k Sorted Lists

        Problem:
        You are given an array of k linked-lists, each sorted in ascending order.
        Merge all the linked-lists into one sorted linked-list and return it.

        Approach:
        Use a min-heap to always select the smallest current node across all lists.
        Each time we extract the smallest node and push its next node (if any) back into the heap.

        Time Complexity: O(N log k), where N is the total number of nodes.
        Space Complexity: O(k) for the min-heap.
        */

        // Define a comparator to order ListNode pointers by their value.
        struct Compare {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;  // Min-heap: smaller values have higher priority.
            }
        };

        // Declare a priority queue (min-heap) that stores ListNode pointers.
        priority_queue<ListNode*, vector<ListNode*>, Compare> min_heap;

        // Push the head of each non-empty list into the min_heap.
        for (int idx = 0; idx < lists.size(); idx++) {
            ListNode* node = lists[idx];
            if (node != nullptr) {
                min_heap.push(node);
            }
        }

        // Create a dummy node to build the merged linked list.
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // Extract the smallest node from the heap and build the result list.
        while (!min_heap.empty()) {
            ListNode* node = min_heap.top();
            min_heap.pop();

            current->next = node;
            current = current->next;

            if (node->next != nullptr) {
                min_heap.push(node->next);  // Push the next node from the same list.
            }
        }

        return dummy->next;  // Return the head of the merged list.
    }
};

