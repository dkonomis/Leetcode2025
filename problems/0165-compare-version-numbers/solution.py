class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        """
        0165 - Compare Version Numbers
        
        Compare two version strings by their numeric values, ignoring leading zeros.
        Missing revisions are treated as 0.
        
        Approach:
        - Split both versions by '.' to get revision arrays
        - Compare revisions one by one from left to right
        - Convert each revision to integer to ignore leading zeros
        - If one version has fewer revisions, treat missing ones as 0
        - Return -1, 0, or 1 based on comparison result
        
        Time complexity: O(n + m).
        Space complexity: O(n + m).
        """
        revisions1 = version1.split('.')
        revisions2 = version2.split('.')
        
        # Get the maximum length to handle different revision counts.
        max_length = max(len(revisions1), len(revisions2))
        
        # Compare each revision from left to right.
        for i in range(max_length):
            # Get revision value or 0 if index is out of bounds.
            rev1 = int(revisions1[i]) if i < len(revisions1) else 0
            rev2 = int(revisions2[i]) if i < len(revisions2) else 0
            
            # Compare current revisions.
            if rev1 < rev2:
                return -1
            elif rev1 > rev2:
                return 1
        
        # All revisions are equal.
        return 0
