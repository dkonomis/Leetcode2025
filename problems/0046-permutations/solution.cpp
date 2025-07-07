class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        /*
        0046. Permutations

        Given a list of distinct integers nums, return all possible permutations.

        Approach:
        - Use backtracking to generate permutations incrementally.
        - Keep a 'path' vector for the current permutation.
        - Use a 'used' boolean vector to mark which elements are already in 'path'.
        - When the 'path' is of size equal to nums, we have a complete permutation.

        Time complexity: O(N*N!)
        - There are N! permutations of N distinct numbers.
        - Each permutation takes O(N) time to build and copy.

        Space complexity: O(N)
        - We use recursion depth and a path of size N.
        */

        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        function<void()> backtrack = [&]() {
            // Base case: all numbers used, store a copy of the current permutation.
            if (path.size() == nums.size()) {
                res.push_back(path);
                return;
            }

            // Try each unused number at the current position in the permutation.
            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;

                // Choose nums[i].
                used[i] = true;
                path.push_back(nums[i]);

                // Recurse with nums[i] included.
                backtrack();

                // Backtrack: remove nums[i] and mark as unused.
                path.pop_back();
                used[i] = false;
            }
        };

        backtrack();
        return res;
    }
};


