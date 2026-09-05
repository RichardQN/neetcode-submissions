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
        vector<vector<int>> res;
        if (!root){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int length = 0;

        while (!q.empty()){
            int leng = q.size();
            res.push_back({});

            for (int i = 0; i < leng; i++){
                TreeNode* node = q.front();
                res[length].push_back(node->val);
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                
            }
            length++;


        }
        return res;
    }
};
