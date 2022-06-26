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
    int go(TreeNode *root,bool &ans)
    {
        if(root==NULL) return 0;
        
        int lh = go(root->left,ans);
        int rh = go(root->right,ans);
        
        if(abs(lh-rh)>1) ans = 0;
        
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        
        bool ans = 1;
        go(root,ans);
        return ans;
        
    }
};