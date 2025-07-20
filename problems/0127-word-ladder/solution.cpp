class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
        Problem: 0127 - Word Ladder
        
        Find the length of shortest transformation sequence from beginWord to endWord.
        
        Approach:
        1. Build a graph using intermediate states (e.g., "h*t" connects "hit" and "hot").
        2. Use BFS to find shortest path length.
        3. Each intermediate state groups words that differ by exactly one letter.
        4. Much faster than generating all possible neighbors on-the-fly.
        
        Time complexity: O(M * N) where M is word length and N is wordList size.
        Space complexity: O(M * N) for the graph and visited set.
        */
        
        // Check if endWord exists in wordList.
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        if (word_set.find(endWord) == word_set.end()) {
            return 0;
        }
        
        int L = beginWord.length();
        
        // Build graph using intermediate states.
        unordered_map<string, vector<string>> graph;
        for (const string& word : wordList) {
            for (int i = 0; i < L; i++) {
                // Create intermediate state by replacing one letter with '*'.
                string key = word.substr(0, i) + '*' + word.substr(i + 1);
                graph[key].push_back(word);
            }
        }
        
        // BFS to find shortest transformation sequence.
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited = {beginWord};
        
        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();
            
            // Try all intermediate states for current word.
            for (int i = 0; i < L; i++) {
                string key = word.substr(0, i) + '*' + word.substr(i + 1);
                
                // Check all words connected through this intermediate state.
                if (graph.find(key) != graph.end()) {
                    for (const string& neighbor : graph[key]) {
                        // Found the target word!
                        if (neighbor == endWord) {
                            return level + 1;
                        }
                        
                        // Add unvisited neighbor to queue.
                        if (visited.find(neighbor) == visited.end()) {
                            visited.insert(neighbor);
                            q.push({neighbor, level + 1});
                        }
                    }
                }
            }
        }
        
        // No transformation sequence found.
        return 0;
    }
};
