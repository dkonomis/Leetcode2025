class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        /*
        Problem: 0093 - Restore IP Addresses

        Given a string s containing only digits, return all possible valid IP addresses
        that can be formed by inserting dots into s. A valid IP consists of four integers,
        each between 0 and 255, and no leading zeros unless the segment is exactly "0".

        Approach:
        - Use backtracking to try placing three dots to divide the string into 4 parts.
        - At each level, take 1 to 3 digits as a candidate segment.
        - Skip segments that are invalid: start with '0' but length > 1, or value > 255.
        - If we build 4 valid parts and use the entire string, add it to the result.

        Time complexity: O(1) — bounded since it's at most 3^4 combinations.
        Space complexity: O(1) auxiliary + O(R) result list where R is number of valid IPs.
        */
        vector<string> res;
        vector<string> path;

        function<void(int)> backtrack = [&](int start) {
            // If we've built 4 segments and used all characters, store the IP.
            if (path.size() == 4) {
                if (start == s.size()) {
                    res.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
                }
                return;
            }

            // Try to take 1 to 3 characters as the next segment.
            for (int len = 1; len <= 3; ++len) {
                // Stop if the substring would go out of bounds.
                if (start + len > s.size()) break;

                string segment = s.substr(start, len);

                // Skip segments with leading zeros (except "0") or value > 255.
                if ((segment[0] == '0' && segment.size() > 1) || stoi(segment) > 255) {
                    continue;
                }

                // Choose the segment.
                path.push_back(segment);

                // Recurse with updated index.
                backtrack(start + len);

                // Backtrack to explore other segmentations.
                path.pop_back();
            }
        };

        // Start backtracking from index 0.
        backtrack(0);
        return res;
    }
};

