# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Codec:
    def serialize(self, root):
        """
        Problem: 0297 - Serialize and Deserialize Binary Tree
        
        Encodes a tree to a single string using level-order traversal (BFS).
        We use a queue to traverse the tree level by level, encoding null nodes
        as "null" to preserve the tree structure.
        
        Time complexity: O(n), where n is the number of nodes.
        Space complexity: O(n) for the queue and result string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ""
        
        res = []
        queue = deque([root])
        
        # Level-order traversal using queue.
        while queue:
            node = queue.popleft()
            if node:
                res.append(str(node.val))
                # Add children to queue even if they're None.
                queue.append(node.left)
                queue.append(node.right)
            else:
                res.append("null")
        
        # Remove trailing nulls for efficiency.
        while res and res[-1] == "null":
            res.pop()
        
        return ",".join(res)
        
    def deserialize(self, data):
        """
        Decodes your encoded data to tree using level-order reconstruction.
        We use a queue to keep track of parent nodes and assign children
        from the serialized data.
        
        Time complexity: O(n), where n is the number of nodes.
        Space complexity: O(n) for the queue and data array.
        
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        
        # Split the data into tokens.
        tokens = data.split(",")
        root = TreeNode(int(tokens[0]))
        queue = deque([root])
        i = 1
        
        # Process tokens to build tree level by level.
        while queue and i < len(tokens):
            node = queue.popleft()
            
            # Process left child.
            if i < len(tokens) and tokens[i] != "null":
                node.left = TreeNode(int(tokens[i]))
                queue.append(node.left)
            i += 1
            
            # Process right child.
            if i < len(tokens) and tokens[i] != "null":
                node.right = TreeNode(int(tokens[i]))
                queue.append(node.right)
            i += 1
        
        return root
