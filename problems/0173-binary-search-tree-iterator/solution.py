# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class BSTIterator:
    """
    0173 - Binary Search Tree Iterator
    
    Implement iterator over in-order traversal of BST with O(1) average time and O(h) space.
    Use stack to simulate in-order traversal on-demand instead of pre-computing all values.
    
    Approach:
    - Maintain stack containing path from root to current leftmost node
    - next(): Pop from stack (current smallest), push right subtree's left path
    - hasNext(): Check if stack is non-empty
    - Key insight: In-order traversal visits left, root, right
    
    Time complexity: O(1) average for both operations.
    Space complexity: O(h) where h is height of tree.
    """

    def __init__(self, root: Optional[TreeNode]):
        """Initialize iterator with root of BST."""
        self.stack = []
        # Push all left nodes from root to establish initial state.
        self._push_left_path(root)

    def next(self) -> int:
        """
        Returns next smallest number in BST.
        
        Returns:
            Next smallest value in in-order traversal
        """
        # Pop the next node (smallest unvisited).
        node = self.stack.pop()
        
        # If this node has right subtree, push its left path.
        # This maintains the in-order property.
        if node.right:
            self._push_left_path(node.right)
        
        return node.val

    def hasNext(self) -> bool:
        """
        Returns True if there are more elements to iterate.
        
        Returns:
            True if more elements exist, False otherwise
        """
        return len(self.stack) > 0

    def _push_left_path(self, node: Optional[TreeNode]) -> None:
        """
        Helper method to push all left nodes starting from given node.
        This simulates going to the leftmost node in in-order traversal.
        
        Args:
            node: Starting node to push left path from
        """
        while node:
            self.stack.append(node)
            node = node.left


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
