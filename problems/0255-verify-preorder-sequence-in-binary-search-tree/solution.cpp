class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        /**
         * Problem: 0255 - Verify Preorder Sequence in Binary Search Tree
         * 
         * Use a stack to track the path from root to current node. When we
         * encounter a value greater than stack top, we're moving to the right
         * subtree. Pop all smaller values and update the lower bound to ensure
         * BST property is maintained.
         * 
         * Time complexity: O(n) where n is the length of preorder.
         * Space complexity: O(n) for the stack.
         */
        
        stack<int> stk;
        int lower_bound = INT_MIN;
        
        for (int val : preorder) {
            // BST property violated: right subtree value < parent.
            if (val < lower_bound) {
                return false;
            }
            
            // Pop all nodes that are less than current value.
            // We're moving to the right subtree of some ancestor.
            while (!stk.empty() && stk.top() < val) {
                lower_bound = stk.top();
                stk.pop();
            }
            
            // Push current value to stack.
            stk.push(val);
        }
        
        return true;
    }
};
