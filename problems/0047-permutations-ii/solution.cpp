#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        /*
        0047. Permutations II

        Given a list of integers nums (which may contain duplicates), return all unique permutations.

        Approach:
        - Sort the input to ensure duplicates are adjacent.
        - Use backtracking to explore all permutations.
        - Track which elements have been used with a boolean array.
        - Skip over duplicate elements by ensuring that if nums[i] == nums[i - 1],
          we only use nums[i] if nums[i - 1] has been used in the current path.

        Time complexity: O(N*N!), where N is the number of elements in nums.
        There are at most N! permutations, but pruning avoids redundant ones.

        Space complexity: O(N), for the recursion stack and the used array.
        */

        sort(nums.begin(), nums.end());  // Sort to detect duplicates.
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        function<void()> backtrack = [&]() {
            // If the path is complete, add a copy to results.
            if (path.size() == nums.size()) {
                res.push_back(path);
                return;
            }

            // Explore choices for the current position.
            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;  // Skip if already used.

                // Skip duplicates: only use the first unused duplicate at each level.
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

                // Choose nums[i].
                used[i] = true;
                path.push_back(nums[i]);

                // Recurse.
                backtrack();

                // Backtrack.
                path.pop_back();
                used[i] = false;
            }
        };

        backtrack();  // Start the recursion.
        return res;
    }
};

