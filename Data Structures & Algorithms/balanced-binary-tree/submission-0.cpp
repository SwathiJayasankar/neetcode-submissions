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
    int helper(TreeNode* root){
        if(!root) return 0;

        int leftHt = helper(root->left);
        if(leftHt == -1) return -1;

        int rightHt = helper(root->right);
        if(rightHt == -1) return -1;

        if(abs(leftHt - rightHt) > 1) return -1;

        return max(leftHt, rightHt)+1;
    }

    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }
};
