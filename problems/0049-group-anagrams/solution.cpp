#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        49. Group Anagrams

        Summary:
        Group all strings that are anagrams into separate lists. Two words are anagrams
        if they contain the same letters in any order (with same counts).

        Approach:
        - Use an unordered_map to group words by their sorted character string.
        - The sorted string acts as a canonical key for each group of anagrams.
        - Append each word to the corresponding group in the map.
        - Return all groups as a vector of string vectors.

        Time complexity: O(N * K log K), where N is the number of words and K is the maximum word length.
        Space complexity: O(N * K), for storing the grouped anagrams.
        */
        unordered_map<string, vector<string>> anagram_map;  // maps sorted string → list of words.

        for (const string& word : strs) {
            string key = word;  // make a copy to sort.
            sort(key.begin(), key.end());  // canonical form of the word.
            anagram_map[key].push_back(word);  // group by sorted key.
        }

        vector<vector<string>> res;  // result list of anagram groups.
        for (auto& pair : anagram_map) {
            res.push_back(pair.second);  // collect each group.
        }

        return res;
    }
};

