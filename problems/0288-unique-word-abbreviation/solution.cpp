class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> abbr_map;
    
    string get_abbreviation(const string& word) {
        // Words with length <= 2 have no abbreviation.
        if (word.length() <= 2) {
            return word;
        }
        // Format: first_letter + middle_length + last_letter.
        return word[0] + to_string(word.length() - 2) + word.back();
    }
    
public:
    ValidWordAbbr(vector<string>& dictionary) {
        /**
         * Problem: 0288 - Unique Word Abbreviation
         * 
         * Design a data structure to check if a word's abbreviation is unique
         * in a dictionary. An abbreviation is unique if no other word shares
         * the same abbreviation, or if all words with that abbreviation are
         * the same word.
         * 
         * Approach:
         * - Map each abbreviation to a set of words that have it
         * - For uniqueness check: abbreviation doesn't exist OR 
         *   only contains the query word
         * 
         * Time complexity: O(n) for initialization where n is dictionary size.
         * Space complexity: O(n) to store abbreviation mappings.
         */
        
        // Build abbreviation map.
        for (const string& word : dictionary) {
            string abbr = get_abbreviation(word);
            abbr_map[abbr].insert(word);
        }
    }
    
    bool isUnique(string word) {
        /**
         * Check if word's abbreviation is unique.
         * Returns true if:
         * 1. No word in dictionary has this abbreviation, OR
         * 2. All words with this abbreviation are the same as query word
         * 
         * Time complexity: O(1) for lookup.
         * Space complexity: O(1) for the check.
         */
        string abbr = get_abbreviation(word);
        
        // Case 1: Abbreviation not in dictionary.
        if (abbr_map.find(abbr) == abbr_map.end()) {
            return true;
        }
        
        // Case 2: Check if all words with this abbr are the same as word.
        // This is true when the set contains only the query word.
        return abbr_map[abbr].size() == 1 && abbr_map[abbr].count(word) > 0;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
