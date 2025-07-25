class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        /**
         * Problem: 0271 - Encode and Decode Strings
         * 
         * Encode a list of strings into a single string that can be decoded back.
         * 
         * Approach: Use length-prefix encoding. For each string, encode as "length#string".
         * This handles any ASCII characters including special ones. The # delimiter after
         * the length ensures we can parse the length correctly.
         * 
         * Time complexity: O(n) where n is total number of characters in all strings.
         * Space complexity: O(n) for the encoded string.
         */
        
        string encoded = "";
        for (const string& s : strs) {
            // Encode each string as "length#string".
            encoded += to_string(s.length()) + '#' + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        /**
         * Decode the encoded string back to list of strings.
         * 
         * Approach: Parse length prefix, then extract exact number of characters.
         * This avoids delimiter collision issues since we know exact string length.
         * 
         * Time complexity: O(n) where n is length of encoded string.
         * Space complexity: O(n) for the decoded list.
         */
        
        vector<string> res;
        int i = 0;
        
        while (i < s.length()) {
            // Find the delimiter '#' to get length.
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            // Parse the length.
            int length = stoi(s.substr(i, j - i));
            
            // Extract the string of given length.
            int start = j + 1;
            res.push_back(s.substr(start, length));
            
            // Move to next encoded string.
            i = start + length;
        }
        
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
