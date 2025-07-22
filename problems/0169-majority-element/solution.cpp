class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        Problem: 0169 - Majority Element
        
        Find element that appears more than ⌊n/2⌋ times in array.
        Guaranteed that majority element always exists.
        
        Approach:
        - Use Boyer-Moore Voting Algorithm for O(n) time, O(1) space
        - Think of it as "voting" - different elements cancel each other out
        - Majority element will survive because it appears > n/2 times
        - Maintain candidate and count: if count=0, pick new candidate
        - If current element matches candidate, increment count; otherwise decrement
        
        Time complexity: O(n).
        Space complexity: O(1).
        */
        
        int candidate = 0;
        int count = 0;
        
        // Boyer-Moore Voting Algorithm.
        for (int num : nums) {
            // If count is 0, we need a new candidate.
            if (count == 0) {
                candidate = num;
                count = 1;
            }
            // If current number matches candidate, they support each other.
            else if (num == candidate) {
                count++;
            }
            // If current number is different, they cancel each other out.
            else {
                count--;
            }
        }
        
        // Since majority element is guaranteed to exist, candidate is the answer.
        return candidate;
    }
};
