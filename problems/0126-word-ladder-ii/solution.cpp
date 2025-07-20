class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        /*
        Problem: 0126 - Word Ladder II
        
        Find all shortest transformation sequences from beginWord to endWord.
        
        Approach:
        1. Use BFS to find shortest distance and build parent graph.
        2. Stop BFS when first reaching endWord (shortest distance found).
        3. Use DFS to reconstruct all paths by following parent relationships backward.
        4. Reverse the paths to get correct order.
        
        Time complexity: O(M * N * 26) for BFS + O(K) for DFS where M is word length, N is wordList size, K is number of paths.
        Space complexity: O(N) for parent map and visited set.
        */
        
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        if (word_set.find(endWord) == word_set.end()) {
            return {};
        }
        
        unordered_map<string, vector<string>> parents;
        parents[beginWord] = {};
        
        // BFS to build parent graph and find shortest distance.
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited = {beginWord};
        bool found = false;
        
        while (!q.empty() && !found) {
            // Process all words at current level before moving to next level.
            unordered_set<string> current_level_words;
            
            // Process each word in current level.
            for (int level_size = q.size(); level_size > 0; level_size--) {
                string current = q.front();
                q.pop();
                
                // Try all possible one-letter changes.
                for (int i = 0; i < current.length(); i++) {
                    string neighbor = current;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c != current[i]) {
                            neighbor[i] = c;
                            
                            // Check if we reached the target word.
                            if (neighbor == endWord) {
                                found = true;
                            }
                            
                            // Add neighbor if it's valid and not yet visited.
                            if (word_set.count(neighbor) && !visited.count(neighbor)) {
                                // Only add to queue once per level.
                                if (!current_level_words.count(neighbor)) {
                                    current_level_words.insert(neighbor);
                                    q.push(neighbor);
                                    parents[neighbor] = {};
                                }
                                
                                // Build reverse edge: neighbor <- current.
                                parents[neighbor].push_back(current);
                            }
                        }
                    }
                }
            }
            
            // Mark all words discovered at this level as visited.
            for (const string& word : current_level_words) {
                visited.insert(word);
            }
        }
        
        // DFS to reconstruct all shortest paths.
        vector<vector<string>> res;
        if (found) {
            vector<string> path;
            buildPaths(endWord, beginWord, parents, path, res);
        }
        
        return res;
    }
    
private:
    void buildPaths(const string& word, const string& beginWord, 
                   const unordered_map<string, vector<string>>& parents,
                   vector<string>& path, vector<vector<string>>& res) {
        // Add current word to path.
        path.push_back(word);
        
        // Base case: reached the beginning word.
        if (word == beginWord) {
            // Reverse path since we built it backward from endWord.
            vector<string> complete_path(path.rbegin(), path.rend());
            res.push_back(complete_path);
        } else {
            // Recursively explore all parents of current word.
            auto it = parents.find(word);
            if (it != parents.end()) {
                for (const string& parent : it->second) {
                    // Continue with parent (path already includes current word).
                    buildPaths(parent, beginWord, parents, path, res);
                }
            }
        }
        
        // Backtrack: remove current word from path.
        path.pop_back();
    }
};
