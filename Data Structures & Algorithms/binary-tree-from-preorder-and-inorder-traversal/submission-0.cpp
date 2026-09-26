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
    unordered_map<int, int> m;  
    int idx = 0;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left, int right){
        if(left > right) return NULL;
       
        int rootval = preorder[idx++];
        TreeNode* root = new TreeNode(rootval);

        int pos = m[rootval];
        root->left = helper(preorder, inorder, left, pos-1);
        root->right = helper(preorder, inorder, pos+1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0; i< inorder.size(); i++){
            m[inorder[i]] = i;
        }

        return helper(preorder, inorder, 0, inorder.size()-1);
    }
};
