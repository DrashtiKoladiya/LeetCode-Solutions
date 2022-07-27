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
    TreeNode* last;
    void go(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        
        go(root->right);
        go(root->left);
        
        root->right = last;
        root->left = NULL;
        
        last = root;
        
    }
    void flatten(TreeNode* root) {
        
        if(root==NULL)
        {
            return;
        }
        last = NULL;
        go(root);
        
        
    }
};