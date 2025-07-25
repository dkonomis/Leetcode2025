/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        /**
         * Problem: 0297 - Serialize and Deserialize Binary Tree
         * 
         * Encodes a tree to a single string using level-order traversal (BFS).
         * We use a queue to traverse the tree level by level, encoding null nodes
         * as "null" to preserve the tree structure.
         * 
         * Time complexity: O(n), where n is the number of nodes.
         * Space complexity: O(n) for the queue and result string.
         */
        
        if (!root) return "";
        
        string res;
        queue<TreeNode*> q;
        q.push(root);
        
        // Level-order traversal using queue.
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                res += to_string(node->val) + ",";
                // Add children to queue even if they're NULL.
                q.push(node->left);
                q.push(node->right);
            } else {
                res += "null,";
            }
        }
        
        // Remove trailing nulls and commas for efficiency.
        while (res.size() >= 5 && res.substr(res.size() - 5) == "null,") {
            res = res.substr(0, res.size() - 5);
        }
        
        // Remove last comma.
        if (!res.empty() && res.back() == ',') {
            res.pop_back();
        }
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        /**
         * Decodes your encoded data to tree using level-order reconstruction.
         * We use a queue to keep track of parent nodes and assign children
         * from the serialized data.
         * 
         * Time complexity: O(n), where n is the number of nodes.
         * Space complexity: O(n) for the queue and tokens.
         */
        
        if (data.empty()) return nullptr;
        
        // Parse tokens from the string.
        vector<string> tokens;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        
        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        
        // Process tokens to build tree level by level.
        while (!q.empty() && i < tokens.size()) {
            TreeNode* node = q.front();
            q.pop();
            
            // Process left child.
            if (i < tokens.size() && tokens[i] != "null") {
                node->left = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }
            i++;
            
            // Process right child.
            if (i < tokens.size() && tokens[i] != "null") {
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
            i++;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
