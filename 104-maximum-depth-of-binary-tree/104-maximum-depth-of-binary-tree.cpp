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
    void go(TreeNode* root, int &depth,int level)
    {
        if(root==NULL) return;
        
        depth = max(depth,level);
        
        go(root->left,depth,level+1);
        go(root->right,depth,level+1);
    }
    int maxDepth(TreeNode* root) {
        
        int depth = 0,level=1;
        go(root,depth,level);
        return depth;   
    }
};