class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /*
        Problem: 0118 - Pascal's Triangle
        
        Generate the first numRows of Pascal's triangle.
        
        Approach:
        1. Build each row using the previous row.
        2. First and last elements of each row are always 1.
        3. Middle elements are sum of two elements above from previous row.
        
        Time complexity: O(numRows^2) where numRows is the input.
        Space complexity: O(1) excluding the output space.
        */
        
        if (numRows == 0) {
            return {};
        }
        
        vector<vector<int>> res;
        
        for (int i = 0; i < numRows; i++) {
            // Create new row with correct size, filled with 1s.
            vector<int> row(i + 1, 1);
            
            // Fill middle elements using previous row.
            for (int j = 1; j < i; j++) {
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            
            res.push_back(row);
        }
        
        return res;
    }
};
