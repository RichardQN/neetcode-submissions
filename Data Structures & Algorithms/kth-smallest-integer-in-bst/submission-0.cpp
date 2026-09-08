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

    void dfs(TreeNode* r, vector<int>& p){
        if (!r){
            return;
        }
        dfs(r->left, p);
        if (p[0] == 0){return;}

        p[0]--;
        if (p[0] == 0){
            p[1] = r->val;
            return;
        }
        dfs(r->right, p);

    }
};
