class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        Problem: 0136 - Single Number
        
        Find the single number in array where every other element appears twice.
        
        Approach:
        1. Use XOR operation on all numbers.
        2. XOR properties: a ^ a = 0, a ^ 0 = a, XOR is commutative and associative.
        3. All pairs cancel out (become 0), leaving only the single number.
        
        Time complexity: O(n) where n is length of nums.
        Space complexity: O(1) using only constant extra space.
        */
        
        int single = 0;
        
        // XOR all numbers - pairs will cancel out.
        for (int num : nums) {
            single ^= num;
        }
        
        return single;
    }
};
