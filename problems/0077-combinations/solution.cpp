class Solution {
public:
    /*
    Problem: 0077 - Combinations

    Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

    Approach:
    - Use backtracking to explore all combinations.
    - At each recursion, pick the next number starting from 'start'.
    - Stop when the current combination contains exactly k numbers.
    - Optimization: prune the search space early if there aren't enough numbers left to complete a combination.

    Time Complexity: O(C(n, k)), where C(n, k) is the number of valid combinations.
    Space Complexity: O(k) for the current combination stack.
    */
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;

        function<void(int)> backtrack = [&](int start) {
            // If we have a complete combination, add it to the result.
            if (path.size() == k) {
                res.push_back(path);
                return;
            }

            // Prune: stop if not enough elements left to complete the combination.
            for (int i = start; i <= n - (k - path.size()) + 1; ++i) {
                path.push_back(i);  // Choose number i.
                backtrack(i + 1);   // Recurse with next start.
                path.pop_back();    // Backtrack to explore other options.
            }
        };

        backtrack(1);
        return res;
    }
};

