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
        vector<vector<int>> res;
        if (!root){
            return res;
        }
        int level = 0;
        q.push(root);

        while (!q.empty()){
            int len = q.size();
            res.push_back({});
            for (int i = 0; i < len;i++){
                TreeNode* node = q.front();
                q.pop();
                res[level].push_back(node->val);

                if (node->left) {q.push(node->left);}
                if (node->right) {q.push(node->right);}
            }
            level++;
        }
        return res;
    }
};
