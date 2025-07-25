class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /**
         * Problem: 0287 - Find the Duplicate Number
         * 
         * Find the duplicate in an array of n+1 integers where each integer
         * is in range [1,n]. Uses Floyd's cycle detection algorithm (tortoise
         * and hare) treating the array as a linked list.
         * 
         * Approach:
         * - Treat array as implicit linked list: index -> nums[index]
         * - Since values are in [1,n] and array has n+1 positions, 
         *   index 0 will never be pointed to (cycle entry point)
         * - Duplicate number creates a cycle in this implicit graph
         * - Use Floyd's algorithm to find cycle start
         * 
         * Time complexity: O(n) for two traversals.
         * Space complexity: O(1) using only two pointers.
         */
        
        // Phase 1: Find intersection point in the cycle.
        int slow = nums[0];
        int fast = nums[0];
        
        // Move until they meet inside the cycle.
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // Phase 2: Find the entrance to the cycle.
        slow = nums[0];
        
        // Move both one step at a time until they meet.
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
