class Solution {
public:
    /*
    Problem: 0078 - Subsets

    Given a list of unique integers, return all possible subsets (the power set).

    Approach:
    - Use backtracking to explore each element's inclusion or exclusion.
    - At each recursive call, record the current subset path.
    - Recurse forward to explore adding more elements.
    - Always include a copy of the current path in the result.

    Time Complexity: O(n × 2^n), where n is the number of elements in nums.
    Space Complexity: O(n) for the recursion call stack.
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;

        backtrack(0, nums, path, res);
        return res;
    }

private:
    // Backtracking helper to build all subsets.
    void backtrack(int start, vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);  // Add the current subset to the result.

        // Explore further elements to include in the subset.
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);         // Choose nums[i].
            backtrack(i + 1, nums, path, res); // Recurse forward.
            path.pop_back();                 // Backtrack by removing last element.
        }
    }
};

