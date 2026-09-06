/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        if (!root){return res;}
        int levelSize = 0;

        while (!q.empty()){
            int levelCount = q.size();
            res.push_back({});
            for (int i = 0; i < levelCount; i++){
                TreeNode* node = q.front();
                res[levelSize].push_back(node->val);
                q.pop();

                if (node->left) {q.push(node->left);}
                if (node->right) {q.push(node->right);}

    
            }
            levelSize++;
        }
        return res;
    }
};
