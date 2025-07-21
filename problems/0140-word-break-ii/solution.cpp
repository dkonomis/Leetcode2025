class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        /*
        Problem: 0140 - Word Break II
        
        Return all possible sentences formed by segmenting string with dictionary words.
        
        Approach:
        1. Use classic backtracking to explore all possible word combinations.
        2. Build path incrementally and backtrack by removing last word.
        3. Join path to form complete sentence when reaching end.
        
        Time complexity: O(2^n * n) in worst case where n is string length.
        Space complexity: O(2^n * n) for storing all possible sentences.
        */
        
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        vector<string> res;
        vector<string> path;
        
        backtrack(s, 0, word_set, path, res);
        return res;
    }
    
private:
    void backtrack(const string& s, int start, const unordered_set<string>& word_set, 
                   vector<string>& path, vector<string>& res) {
        // Base case: reached end of string.
        if (start == s.length()) {
            res.push_back(joinPath(path));
            return;
        }
        
        // Try all possible words starting from current position.
        for (int end = start + 1; end <= s.length(); end++) {
            string word = s.substr(start, end - start);
            
            // If current word is in dictionary, continue backtracking.
            if (word_set.count(word)) {
                // Choose.
                path.push_back(word);
                // Explore.
                backtrack(s, end, word_set, path, res);
                // Unchoose (backtrack).
                path.pop_back();
            }
        }
    }
    
    string joinPath(const vector<string>& path) {
        if (path.empty()) return "";
        
        string res = path[0];
        for (int i = 1; i < path.size(); i++) {
            res += " " + path[i];
        }
        return res;
    }
};
