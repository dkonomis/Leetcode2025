class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /**
         * Problem: 0229 - Majority Element II
         * 
         * Find all elements appearing more than n/3 times.
         * Use Boyer-Moore Voting Algorithm with two candidates.
         * At most 2 elements can appear more than n/3 times.
         * First pass: find potential candidates.
         * Second pass: verify candidates actually appear > n/3 times.
         * 
         * Time complexity: O(n) with two passes through the array.
         * Space complexity: O(1) using only constant extra space.
         */
        
        // Phase 1: Find at most 2 potential candidates.
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;
        
        for (int num : nums) {
            // If num matches a candidate, increment its count.
            if (candidate1 == num) {
                count1++;
            } else if (candidate2 == num) {
                count2++;
            }
            // If a count is 0, replace that candidate.
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            // If num doesn't match either candidate, decrement both counts.
            else {
                count1--;
                count2--;
            }
        }
        
        // Phase 2: Verify candidates appear more than n/3 times.
        vector<int> res;
        int threshold = nums.size() / 3;
        
        // Count occurrences of each candidate.
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }
        
        // Add to result if appears more than n/3 times.
        if (count1 > threshold) {
            res.push_back(candidate1);
        }
        if (candidate1 != candidate2 && count2 > threshold) {
            res.push_back(candidate2);
        }
        
        return res;
    }
};
