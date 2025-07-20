class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
        Problem: 0128 - Longest Consecutive Sequence
        
        Find the length of longest consecutive elements sequence.
        
        Approach:
        1. Use hash set for O(1) lookups.
        2. Only start counting sequences from their beginning.
        3. For each number x, only count if x-1 is not in set.
        4. This ensures each sequence is counted exactly once.
        
        Time complexity: O(n) where n is length of nums.
        Space complexity: O(n) for the hash set.
        */
        
        if (nums.empty()) {
            return 0;
        }
        
        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_length = 0;
        
        for (int num : num_set) {
            // Only start a sequence if this is the beginning.
            if (num_set.find(num - 1) == num_set.end()) {
                int current_num = num;
                int current_length = 1;
                
                // Count consecutive numbers starting from current_num.
                while (num_set.find(current_num + 1) != num_set.end()) {
                    current_num++;
                    current_length++;
                }
                
                // Update maximum length found.
                max_length = max(max_length, current_length);
            }
        }
        
        return max_length;
    }
};
