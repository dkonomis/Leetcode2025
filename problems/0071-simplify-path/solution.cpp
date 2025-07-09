class Solution {
public:
    /*
    Problem: 0071 - Simplify Path

    You are given an absolute Unix-style file path and must convert it into its simplified canonical form.

    Approach:
    - Split the path by '/' to extract directory components.
    - Use a stack to simulate directory navigation:
        - Skip empty strings and "." (current directory).
        - If the component is "..", pop the stack if not empty.
        - Otherwise, push valid directory names onto the stack.
    - Rebuild the path by joining stack components with '/'.
    - Ensure the result starts with a leading '/' and has no trailing slash
      (unless it is the root "/").

    Time Complexity: O(n), where n is the length of the input path.
    Space Complexity: O(n), for the stack used to store path components.
    */
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string part;

        // Process each component in the path to simulate directory navigation.
        while (getline(ss, part, '/')) {
            if (part.empty() || part == ".") {
                continue;  // Ignore empty parts and current directory.
            } else if (part == "..") {
                if (!stack.empty()) {
                    stack.pop_back();  // Move up one level in directory.
                }
            } else {
                stack.push_back(part);  // Valid directory name, push to stack.
            }
        }

        // Reconstruct the canonical path from the stack.
        string simplified = "/";
        for (int i = 0; i < stack.size(); ++i) {
            simplified += stack[i];
            if (i < stack.size() - 1) {
                simplified += "/";
            }
        }

        return simplified;
    }
};

