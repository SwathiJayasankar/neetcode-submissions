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
    int f(TreeNode* root, int maxi){
        if(!root ) return 0;

        int cnt = 0;
        if(root->val >= maxi){
            cnt = 1;
            maxi = root->val;
        }

        cnt += f(root->left, maxi);
        cnt += f(root->right, maxi);

        return cnt;
    }

    int goodNodes(TreeNode* root) {
        return f(root, INT_MIN);
    }
};
