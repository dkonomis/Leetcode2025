class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        /**
         * Problem: 0261 - Graph Valid Tree
         * 
         * Use Union-Find with path compression and union by rank.
         * A valid tree must satisfy:
         * 1. Exactly n-1 edges (connected and no cycles)
         * 2. No cycles when building (union returns False if cycle)
         * 3. All nodes connected (one component at end)
         * 
         * Time complexity: O(E * α(n)) where E is edges, α is inverse Ackermann.
         * Space complexity: O(n) for parent and rank arrays.
         */
        
        // Tree must have exactly n-1 edges.
        if (edges.size() != n - 1) {
            return false;
        }
        
        // Initialize Union-Find structure.
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        // Find with path compression.
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };
        
        // Union by rank, returns false if cycle detected.
        auto unionSets = [&](int x, int y) {
            // Find roots.
            int root_x = find(x);
            int root_y = find(y);
            
            // Already in same component - cycle detected!
            if (root_x == root_y) {
                return false;
            }
            
            // Union by rank.
            if (rank[root_x] < rank[root_y]) {
                parent[root_x] = root_y;
            } else if (rank[root_x] > rank[root_y]) {
                parent[root_y] = root_x;
            } else {
                parent[root_y] = root_x;
                rank[root_x]++;
            }
            
            return true;
        };
        
        // Process all edges.
        for (const auto& edge : edges) {
            if (!unionSets(edge[0], edge[1])) {
                return false;
            }
        }
        
        // Valid tree: no cycles and exactly n-1 edges.
        return true;
    }
};
