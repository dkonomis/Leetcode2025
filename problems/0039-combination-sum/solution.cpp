class Solution {
public:
    /*
    0039. Combination Sum

    Given a list of distinct integers candidates and a target integer target,
    return all unique combinations of candidates where the chosen numbers sum to target.
    Each number in candidates may be used an unlimited number of times.

    Approach:
    Use backtracking to explore all valid combinations. At each recursive call, we try all
    candidates starting from the current index to allow repeated usage. We track the current
    path and running total, and backtrack when the total exceeds the target.

    Time complexity: O(N^(T/M) + 1),
    where N is the number of candidates, T is the target value, and M is the smallest candidate.
    The recursion forms an N-ary tree of height T/M, resulting in at most O(N^(T/M) + 1) calls.

    Space complexity: O(T/M),
    due to the recursion stack and the temporary path list.
    The result container is not included in the space complexity.
    */

    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& candidates, int start, int total, int target) {
        if (total == target) {
            res.push_back(path);
            return;
        }
        if (total > target) {
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Add number in the path.
            path.push_back(candidates[i]);

            // candidates[i] can be included multiple times.
            backtrack(candidates, i, total + candidates[i], target);

            // Remove candidates[i] from path.
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        backtrack(candidates, 0, 0, target);
        return res;
    }
};

