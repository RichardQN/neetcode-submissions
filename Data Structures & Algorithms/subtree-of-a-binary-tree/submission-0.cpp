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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root && subRoot && root->val == subRoot->val){
            if (isSameTree(root, subRoot)) {return true;}
        } 
        if (!root){
            return false;
        } else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }

    }

    bool isSameTree(TreeNode* q, TreeNode* p)
    {
        if (!p && !q){
            return true;
        }
        if (p && q && p->val == q->val){
            return isSameTree(q->left, p->left) && isSameTree(q->right, p->right);
        } else {
            return false;
        }
    }
};
