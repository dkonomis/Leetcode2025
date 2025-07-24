class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        """
        Problem: 0261 - Graph Valid Tree
        
        Use Union-Find with path compression and union by rank.
        A valid tree must satisfy:
        1. Exactly n-1 edges (connected and no cycles)
        2. No cycles when building (union returns False if cycle)
        3. All nodes connected (one component at end)
        
        Time complexity: O(E * α(n)) where E is edges, α is inverse Ackermann.
        Space complexity: O(n) for parent and rank arrays.
        """
        # Tree must have exactly n-1 edges.
        if len(edges) != n - 1:
            return False
        
        # Initialize Union-Find structure.
        parent = list(range(n))
        rank = [0] * n
        
        def find(x):
            # Path compression.
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x, y):
            # Find roots.
            root_x = find(x)
            root_y = find(y)
            
            # Already in same component - cycle detected!
            if root_x == root_y:
                return False
            
            # Union by rank.
            if rank[root_x] < rank[root_y]:
                parent[root_x] = root_y
            elif rank[root_x] > rank[root_y]:
                parent[root_y] = root_x
            else:
                parent[root_y] = root_x
                rank[root_x] += 1
            
            return True
        
        # Process all edges.
        for a, b in edges:
            if not union(a, b):
                return False
        
        # Valid tree: no cycles and exactly n-1 edges.
        return True
