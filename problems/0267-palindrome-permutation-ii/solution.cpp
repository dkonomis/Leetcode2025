class Solution {
public:
    vector<string> generatePalindromes(string s) {
        /**
         * Problem: 0267 - Palindrome Permutation II
         * 
         * Generate all palindromic permutations of a string.
         * 
         * Approach: Count character frequencies. Check if palindrome is possible (at most one
         * odd count). Use backtracking to build palindromes by placing characters symmetrically
         * around the center. Only need to generate the first half since the second half mirrors it.
         * 
         * Time complexity: O((n/2)!) where n is the length of the string.
         * Space complexity: O(n) for recursion stack and character count.
         */
        
        // Count character frequencies.
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        
        // Find middle character for odd-length palindromes.
        string mid = "";
        int odd_count = 0;
        for (auto& [c, freq] : count) {
            if (freq % 2 == 1) {
                odd_count++;
                mid = c;
            }
        }
        
        // More than one odd frequency means no palindrome possible.
        if (odd_count > 1) {
            return {};
        }
        
        // Prepare characters for backtracking (half frequencies).
        string chars = "";
        for (auto& [c, freq] : count) {
            chars += string(freq / 2, c);
        }
        
        // Sort to handle duplicates properly.
        sort(chars.begin(), chars.end());
        
        // Generate all permutations of half string.
        vector<string> res;
        vector<bool> used(chars.size(), false);
        string path = "";
        
        backtrack(chars, path, used, mid, res);
        return res;
    }
    
private:
    void backtrack(const string& chars, string& path, vector<bool>& used, 
                   const string& mid, vector<string>& res) {
        // Complete palindrome found.
        if (path.size() == chars.size()) {
            // Build full palindrome: first_half + mid + reversed_first_half.
            string palindrome = path + mid + string(path.rbegin(), path.rend());
            res.push_back(palindrome);
            return;
        }
        
        // Try each unused character.
        for (int i = 0; i < chars.size(); i++) {
            // Skip if used or duplicate of previous.
            if (used[i] || (i > 0 && chars[i] == chars[i-1] && !used[i-1])) {
                continue;
            }
            
            // Use this character.
            used[i] = true;
            path.push_back(chars[i]);
            // Recursively build the rest of the palindrome with this choice.
            backtrack(chars, path, used, mid, res);
            // Backtrack: undo the choice to try other possibilities.
            path.pop_back();
            used[i] = false;
        }
    }
};
