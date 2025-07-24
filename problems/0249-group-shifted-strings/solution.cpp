class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        /*
         * Problem: 0249 - Group Shifted Strings
         * 
         * Group strings that belong to same shifting sequence.
         * Use hash map with normalized keys representing shift pattern.
         * Normalize by shifting first character to 'a'.
         * 
         * Time complexity: O(n * m) where n is number of strings, m is average length.
         * Space complexity: O(n * m) for the hash map.
         */
        
        unordered_map<string, vector<string>> groups;
        
        for (const string& s : strings) {
            // Calculate the key by normalizing the string.
            // Shift pattern is represented by differences from first character.
            string key = getKey(s);
            
            // Add string to its group.
            groups[key].push_back(s);
        }
        
        // Return all groups as list of lists.
        vector<vector<string>> res;
        for (auto& pair : groups) {
            res.push_back(pair.second);
        }
        
        return res;
    }
    
private:
    string getKey(const string& s) {
        // Get normalized key representing the shift pattern.
        if (s.empty()) {
            return "";
        }
        
        // Normalize by shifting first character to 'a'.
        // This creates a canonical form for each shift pattern.
        int shift = s[0] - 'a';
        string key;
        
        for (char c : s) {
            // Shift character and handle wraparound.
            int normalized = (c - 'a' - shift + 26) % 26;
            key += char(normalized + 'a');
        }
        
        // Return string key.
        return key;
    }
};
