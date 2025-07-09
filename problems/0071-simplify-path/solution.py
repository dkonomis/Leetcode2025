class Solution:
    def simplifyPath(self, path: str) -> str:
        """
        Problem: 0071 - Simplify Path

        You are given an absolute Unix-style file path and must convert it into its simplified canonical form.

        Approach:
        - Split the input path by '/' to extract directory components.
        - Use a stack to simulate directory navigation:
            - Ignore empty segments and '.' (current directory).
            - For '..', pop from the stack (move up one level) if not empty.
            - Otherwise, push valid directory names to the stack.
        - Join the stack contents with '/' and prefix with root '/'.

        Time complexity: O(n), where n is the length of the path string.
        Space complexity: O(n), for the stack used to store valid path components.
        """
        components = path.split('/')
        stack = []

        # Process each component in the path to simulate directory navigation.
        for part in components:
            if part == '' or part == '.':
                continue  # Skip empty or current directory references.
            elif part == '..':
                if stack:
                    stack.pop()  # Go up to parent directory.
            else:
                stack.append(part)  # Valid directory, go deeper.

        # Join the stack into the final canonical path.
        return '/' + '/'.join(stack)

