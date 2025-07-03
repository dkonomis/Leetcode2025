#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        Problem: 0001 - Two Sum.

        Given an array of integers and a target value, return the indices of
        the two numbers such that they add up to the target.

        Approach:
        - Use an unordered_map (hash map) to track values and their indices.
        - For each element, calculate its complement (target - num).
        - If the complement is found in the map, return the two indices.
        - Otherwise, store the current value and its index in the map.

        Time Complexity: O(n).
        Space Complexity: O(n).
        */

        unordered_map<int, int> map; // Value → index.

        for (int i = 0; i < nums.size(); ++i) {
            int remain = target - nums[i]; // Compute complement.
            if (map.find(remain) != map.end()) {
                // Found the complement.
                return {map[remain], i};
            }
            // Store current number and index.
            map[nums[i]] = i;
        }

        // Should not reach here since one valid answer always exists.
        return {};
    }
};
