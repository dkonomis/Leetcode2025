class Solution {
public:
    bool isStrobogrammatic(string num) {
        /*
         * Problem: 0246 - Strobogrammatic Number
         * 
         * Check if number looks same when rotated 180 degrees.
         * Valid rotations: 0->0, 1->1, 6->9, 8->8, 9->6.
         * Use two pointers from both ends and check if digits form valid pairs.
         * 
         * Time complexity: O(n) where n is the length of num.
         * Space complexity: O(1).
         */
        
        // Map of valid digit rotations.
        unordered_map<char, char> rotations = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };
        
        int left = 0;
        int right = num.length() - 1;
        
        // Check digits from both ends moving inward.
        while (left <= right) {
            // Check if left digit can be rotated.
            if (rotations.find(num[left]) == rotations.end()) {
                return false;
            }
            
            // Check if rotation of left digit matches right digit.
            if (rotations[num[left]] != num[right]) {
                return false;
            }
            
            // Move pointers inward.
            left++;
            right--;
        }
        
        return true;
    }
};
