class Solution {
public:
    /*
    Problem: 0090 - Subsets II

    Given a list of integers that may contain duplicates, return all possible subsets
    (the power set), ensuring no duplicate subsets in the output.

    Approach:
    - Sort the input to group duplicates together.
    - Use backtracking to explore all subset combinations.
    - At each level, skip elements that are the same as the previous one
      (i.e., nums[i] == nums[i - 1]) if we're at the same recursion depth.
    - This avoids generating duplicate subsets.

    Time complexity: O(2^n)
    Space complexity: O(n) for the recursion stack
    */
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;

        sort(nums.begin(), nums.end());  // Sort to group duplicates.

        function<void(int)> backtrack = [&](int start) {
            res.push_back(path);  // Add current subset to result.

            // Explore all next elements starting from 'start' index.
            for (int i = start; i < nums.size(); ++i) {
                // Skip duplicates: if current value equals previous at same level.
                if (i > start && nums[i] == nums[i - 1])
                    continue;

                path.push_back(nums[i]);     // Choose nums[i].
                backtrack(i + 1);            // Recurse with next index.
                path.pop_back();             // Backtrack.
            }
        };

        backtrack(0);
        return res;
    }
};

