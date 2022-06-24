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
    void go(TreeNode *root, int level,vector<vector<int>> &v)
    {
        if(root==NULL) return;
        
        if(v.size()==level) v.push_back({});
        
        v[level].push_back(root->val);
        go(root->left,level+1,v);
        go(root->right,level+1,v);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        go(root,0,ans);
        return ans;
        
    }
};