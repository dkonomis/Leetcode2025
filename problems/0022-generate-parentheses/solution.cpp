#include <vector>
#include <string>

class Solution {
public:
    /*
    Problem 0022 – Generate Parentheses.

    Given n pairs of parentheses, generate all combinations of well-formed parentheses.

    Approach:
    Use backtracking to generate valid sequences character by character.
    At each step:
      - If we still have open parentheses left, we can place '('.
      - If we have more opens than closes so far, we can place ')'.
    We recurse until we've used all 2 * n characters.

    Time Complexity  : O(4^n / sqrt(n)), based on the nth Catalan number.
    Space Complexity : O(n), the depth of the recursion tree and the space for each string.
    */
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string current;

        backtrack(n, 0, 0, current, res);
        return res;
    }

private:
    void backtrack(int n, int open_count, int close_count, std::string& current, std::vector<std::string>& res) {
        // If the current string is complete, add it to the result.
        if (current.length() == 2 * n) {
            res.push_back(current);
            return;
        }

        // If we can still place an open parenthesis, do so.
        if (open_count < n) {
            current.push_back('(');
            backtrack(n, open_count + 1, close_count, current, res);
            current.pop_back();
        }

        // If placing a closing parenthesis won't unbalance the string, do so.
        if (close_count < open_count) {
            current.push_back(')');
            backtrack(n, open_count, close_count + 1, current, res);
            current.pop_back();
        }
    }
};

