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
    bool go(TreeNode *root,long long int mn,long long int mx)
    {
        if(root==NULL) return 1;
        
        if(root->val < mn || root->val > mx) return 0;
        
        bool l = 1;
        if(root->left!=NULL) l = go(root->left, mn, (long long int)root->val - 1);
        bool r = 1;
        if(root->right!=NULL) r = go(root->right, (long long int)root->val+1, mx);
        
        return l&r;
        
    }
    bool isValidBST(TreeNode* root) {
        return go(root,INT_MIN, INT_MAX);
    }
};