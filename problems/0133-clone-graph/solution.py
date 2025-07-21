"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        """
        Problem: 0133 - Clone Graph
        
        Create a deep copy of connected undirected graph.
        
        Approach:
        1. Use BFS to traverse all nodes in the graph.
        2. Use hashmap to track original -> cloned node mapping.
        3. For each node, clone it and all its neighbors.
        4. Connect cloned nodes to cloned neighbors.
        
        Time complexity: O(V + E) where V is vertices and E is edges.
        Space complexity: O(V) for hashmap and queue.
        """
        if not node:
            return None
        
        # HashMap to store original -> cloned node mapping.
        cloned = {}
        
        # BFS queue starting with the given node.
        queue = [node]
        cloned[node] = Node(node.val)
        
        while queue:
            current = queue.pop(0)
            
            # Process all neighbors of current node.
            for neighbor in current.neighbors:
                # If neighbor hasn't been cloned yet, clone it and add to queue.
                if neighbor not in cloned:
                    cloned[neighbor] = Node(neighbor.val)
                    queue.append(neighbor)
                
                # Connect cloned current node to cloned neighbor.
                cloned[current].neighbors.append(cloned[neighbor])
        
        # Return the cloned version of the original starting node.
        return cloned[node]
