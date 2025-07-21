class Solution {
public:
    vector<vector<string>> partition(string s) {
        /*
        Problem: 0131 - Palindrome Partitioning
        
        Find all possible palindrome partitioning of string s.
        
        Approach:
        1. Use backtracking to try all possible partitions.
        2. At each position, try all palindromic substrings starting from that position.
        3. Recursively partition the remaining string.
        4. Add complete partition when reaching end of string.
        
        Time complexity: O(2^n * n) where n is length of string.
        Space complexity: O(n) for recursion stack and current partition.
        */
        
        vector<vector<string>> res;
        vector<string> current_partition;
        backtrack(s, 0, current_partition, res);
        return res;
    }
    
private:
    bool isPalindrome(const string& str) {
        // Check if string is palindrome using two pointers.
        int left = 0, right = str.length() - 1;
        
        // Move pointers toward center.
        while (left < right) {
            // If characters don't match, not a palindrome.
            if (str[left] != str[right]) {
                return false;
            }
            // Move both pointers inward.
            left++;
            right--;
        }
        
        // All characters matched, it's a palindrome.
        return true;
    }
    
    void backtrack(const string& s, int start, vector<string>& current_partition, 
                   vector<vector<string>>& res) {
        // Base case: reached end of string.
        if (start == s.length()) {
            res.push_back(current_partition);  // Vector automatically copies.
            return;
        }
        
        // Try all possible substrings starting from current position.
        for (int end = start + 1; end <= s.length(); end++) {
            string substring = s.substr(start, end - start);
            
            // If substring is palindrome, include it in partition.
            if (isPalindrome(substring)) {
                // Choose: add substring to current partition.
                current_partition.push_back(substring);
                
                // Explore: recursively partition remaining string.
                backtrack(s, end, current_partition, res);
                
                // Unchoose: remove substring for next iteration.
                current_partition.pop_back();
            }
        }
    }
};
