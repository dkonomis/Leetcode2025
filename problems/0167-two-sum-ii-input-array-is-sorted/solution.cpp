class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*
        Problem: 0167 - Two Sum II - Input Array Is Sorted
        
        Find two numbers in sorted array that add up to target.
        Must use constant extra space and return 1-indexed positions.
        
        Approach:
        - Use two pointers technique since array is sorted
        - Start with left at beginning, right at end
        - If sum < target, move left pointer right (increase sum)
        - If sum > target, move right pointer left (decrease sum)  
        - If sum == target, found the answer
        - Guaranteed to have exactly one solution
        
        Time complexity: O(n).
        Space complexity: O(1).
        */
        
        int left = 0, right = numbers.size() - 1;
        
        // Two pointers approach leveraging sorted array property.
        while (left < right) {
            int current_sum = numbers[left] + numbers[right];
            
            // Found target sum, return 1-indexed positions.
            if (current_sum == target) {
                return {left + 1, right + 1};
            }
            
            // Sum too small, need larger number - move left pointer right.
            else if (current_sum < target) {
                left++;
            }
            
            // Sum too large, need smaller number - move right pointer left.
            else {
                right--;
            }
        }
        
        // Should never reach here given problem constraints.
        return {-1, -1};
    }
};
