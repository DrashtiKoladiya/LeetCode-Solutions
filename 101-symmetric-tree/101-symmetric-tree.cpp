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
    bool go(TreeNode *root1, TreeNode *root2)
    {
        if(root1==NULL && root2==NULL) return 1;
        
        if(root1==NULL || root2==NULL) return 0;
        
        if(root1->val != root2->val) return 0;
        
        int ans;
        ans = go(root1->left,root2->right);
        ans&= go(root1->right,root2->left);
        
        return ans;
    }
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return 1;
        
        return go(root->left,root->right);
        
    }
};