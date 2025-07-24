class Vector2D {
private:
    vector<vector<int>> vec;
    int i = 0;  // Current row index.
    int j = 0;  // Current column index.
    
    void forward() {
        // Skip empty lists and advance to next valid position.
        while (i < vec.size() && j >= vec[i].size()) {
            i++;  // Move to next row.
            j = 0;  // Reset column index.
        }
    }
    
public:
    Vector2D(vector<vector<int>>& vec) : vec(vec) {
        /**
         * Problem: 0251 - Flatten 2D Vector
         * 
         * Design an iterator to flatten a 2D vector. Track current position
         * using row index (i) and column index (j). Skip empty lists by
         * advancing indices in the forward() helper method.
         * 
         * Time complexity: O(1) amortized for both next() and hasNext().
         * Space complexity: O(1) excluding input storage.
         */
    }
    
    int next() {
        // Ensure we're at a valid position.
        forward();
        // Get current element and advance column index.
        int res = vec[i][j];
        j++;
        return res;
    }
    
    bool hasNext() {
        // Advance to next valid position if needed.
        forward();
        // Check if we still have elements.
        return i < vec.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
