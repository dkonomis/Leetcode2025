class Solution {
public:
    string alienOrder(vector<string>& words) {
        /**
         * Problem: 0269 - Alien Dictionary
         * 
         * Find the order of characters in an alien language given a sorted dictionary.
         * 
         * Approach: Build a directed graph where edge u->v means u comes before v. Use
         * topological sort to find the character ordering. Detect cycles (invalid order)
         * and handle edge cases like prefix/suffix conflicts.
         * 
         * Time complexity: O(C) where C is total number of characters across all words.
         * Space complexity: O(1) since at most 26 lowercase English letters.
         */
        
        // Build adjacency list and track all unique characters.
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> in_degree;
        
        // Initialize graph with all characters.
        for (const string& word : words) {
            for (char c : word) {
                if (graph.find(c) == graph.end()) {
                    graph[c] = unordered_set<char>();
                    in_degree[c] = 0;
                }
            }
        }
        
        // Build graph by comparing adjacent words.
        for (int i = 0; i < words.size() - 1; i++) {
            const string& word1 = words[i];
            const string& word2 = words[i + 1];
            
            // Find first differing character.
            int min_len = min(word1.length(), word2.length());
            bool found_diff = false;
            
            for (int j = 0; j < min_len; j++) {
                if (word1[j] != word2[j]) {
                    // Add edge word1[j] -> word2[j].
                    if (graph[word1[j]].find(word2[j]) == graph[word1[j]].end()) {
                        graph[word1[j]].insert(word2[j]);
                        in_degree[word2[j]]++;
                    }
                    found_diff = true;
                    break;
                }
            }
            
            // Check invalid case: word1 is prefix of word2 but longer.
            if (!found_diff && word1.length() > word2.length()) {
                return "";
            }
        }
        
        // Topological sort using Kahn's algorithm.
        queue<char> q;
        for (auto& [c, degree] : in_degree) {
            if (degree == 0) {
                q.push(c);
            }
        }
        
        string res = "";
        while (!q.empty()) {
            // Process character with no dependencies.
            char c = q.front();
            q.pop();
            res += c;
            
            // Update neighbors.
            for (char neighbor : graph[c]) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Check if all characters were processed (no cycle).
        if (res.length() != graph.size()) {
            return "";
        }
        
        return res;
    }
};
