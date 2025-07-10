class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        """
        Problem: 0093 - Restore IP Addresses

        Given a string s containing only digits, return all possible valid IP addresses
        that can be formed by inserting dots into s. A valid IP consists of four integers,
        each between 0 and 255, and no leading zeros unless the segment is exactly "0".

        Approach:
        - Use backtracking to generate all segmentations of the string into 4 parts.
        - At each recursive step, try to take 1 to 3 digits as a segment.
        - Validate the segment: must be <= 255 and have no leading zero (unless it is "0").
        - Backtrack once we've either found a valid 4-part IP or exceeded constraints.

        Time complexity: O(1) — worst case is bounded since 4 segments of up to 3 digits.
        Space complexity: O(1) auxiliary + O(R) result list where R is number of valid IPs.
        """
        res = []

        def backtrack(start: int, path: List[str]) -> None:
            # If we've built 4 segments and used all digits, store the IP.
            if len(path) == 4:
                if start == len(s):
                    res.append(".".join(path))
                return

            # Try to take 1 to 3 characters as the next segment.
            for length in range(1, 4):
                # Stop if the next segment would go past the end of the string.
                if start + length > len(s):
                    break

                segment = s[start:start + length]

                # Skip invalid segments: leading zeros or value > 255.
                if (segment.startswith('0') and len(segment) > 1) or int(segment) > 255:
                    continue

                # Choose the segment.
                path.append(segment)

                # Recurse with updated start position and path.
                backtrack(start + length, path)

                # Backtrack to explore other segmentations.
                path.pop()

        # Start backtracking from index 0 with an empty path.
        backtrack(0, [])
        return res

        
