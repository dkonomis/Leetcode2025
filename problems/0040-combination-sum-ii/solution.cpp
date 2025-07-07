// 0040. Combination Sum II

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(int start, int total, vector<int>& candidates, int target) {
        if (total == target) {
            res.push_back(path);
            return;
        }
        if (total > target) {
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicate values at the same level.
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Add candidates[i] to the path.
            path.push_back(candidates[i]);

            // Recurse to the next level. Use i+1 to avoid reusing the same element.
            backtrack(i + 1, total + candidates[i], candidates, target);

            // Backtrack — remove the last added number.
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /*
        0040. Combination Sum II

        Given a collection of integers candidates (which may contain duplicates),
        return all unique combinations where the numbers sum to the given target.
        Each number may be used at most once in each combination.

        Approach:
        - Sort the input to make it easy to skip duplicates at the same recursion level.
        - Use backtracking to explore combinations starting from index 'start'.
        - At the same level, skip repeated values to avoid duplicate results.
        - Track the current path and total sum.
        - Add valid paths to 'res' when the total reaches the target.

        Time complexity: O(2^N), where N is the number of candidates.
        In the worst case, all subsets are explored. Pruning helps in practice.

        Space complexity: O(N).
        This accounts for recursion depth.
        */

        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backtrack(0, 0, candidates, target);
        return res;
    }
};

