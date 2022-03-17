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
    vector<string> ans;
    void go(TreeNode* root,string ans1)
    {
        if(root==NULL)
        {
            return;
        }
        
        ans1+= to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(ans1);
            return;
        }
        
        ans1+= "->";
        go(root->left,ans1);
        go(root->right,ans1);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        ans.clear();
        if(root==NULL)
        {
            return ans;
        }
        
        string ans1 = "";
        
        go(root,ans1);
        
        return ans;
        
    }
};