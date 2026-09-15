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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp(2);
        temp[0] = k;
        dfs(root, temp);
        return temp[1];
        

        
    }

    void dfs(TreeNode* r, vector<int>& temp){
        if (!r){
            return;
        }

        dfs(r->left, temp);
        if (temp[0] == 0){return;}

        temp[0]--;
        if (temp[0] == 0){
            temp[1] = r->val;
            return;
        }
        dfs(r->right, temp);
    }
};
