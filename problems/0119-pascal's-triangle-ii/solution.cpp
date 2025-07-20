class Solution {
public:
    vector<int> getRow(int rowIndex) {
        /*
        Problem: 0119 - Pascal's Triangle II
        
        Return the rowIndex-th row of Pascal's triangle.
        
        Approach:
        1. Use space-optimized in-place construction.
        2. Build each row iteratively using only one array.
        3. Update from right to left to avoid overwriting needed values.
        4. Each iteration extends the array by one element.
        
        Time complexity: O(rowIndex^2) where rowIndex is the input.
        Space complexity: O(rowIndex) for the result array.
        */
        
        // Start with the first row.
        vector<int> row = {1};
        
        // Build each subsequent row up to rowIndex.
        for (int i = 0; i < rowIndex; i++) {
            // Extend row by one element (will be 1).
            row.push_back(1);
            
            // Update elements from right to left to avoid overwriting.
            for (int j = row.size() - 2; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }
        
        return row;
    }
};
