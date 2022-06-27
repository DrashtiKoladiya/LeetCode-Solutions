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
    int mx = 0;
    int go(TreeNode *root)
    {
        if(root==NULL) return 0;
        
        int left = go(root->left);
        int right = go(root->right);
        
        if(left<=0) left=0;
        if(right<=0) right=0;
        
        mx = max(mx,left+right+root->val);
        
        return max({0,left+root->val,right+root->val});
    }
    int maxPathSum(TreeNode* root) {
        mx = INT_MIN;
        
        go(root);
        
        return mx;
    }
};