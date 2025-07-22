class Solution {
public:
    int compareVersion(string version1, string version2) {
        /*
        Problem: 0165 - Compare Version Numbers
        
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
        */
        
        vector<string> revisions1 = splitByDot(version1);
        vector<string> revisions2 = splitByDot(version2);
        
        // Get the maximum length to handle different revision counts.
        int max_length = max(revisions1.size(), revisions2.size());
        
        // Compare each revision from left to right.
        for (int i = 0; i < max_length; i++) {
            // Get revision value or 0 if index is out of bounds.
            int rev1 = (i < revisions1.size()) ? stoi(revisions1[i]) : 0;
            int rev2 = (i < revisions2.size()) ? stoi(revisions2[i]) : 0;
            
            // Compare current revisions.
            if (rev1 < rev2) {
                return -1;
            } else if (rev1 > rev2) {
                return 1;
            }
        }
        
        // All revisions are equal.
        return 0;
    }
    
private:
    vector<string> splitByDot(const string& version) {
        vector<string> revisions;
        stringstream ss(version);
        string revision;
        
        // Split by '.' delimiter.
        while (getline(ss, revision, '.')) {
            revisions.push_back(revision);
        }
        
        return revisions;
    }
};
