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
    vector<int> v;
    void preorderTraversalRecursive(TreeNode* root)
    {
        if(root==NULL) return;
        
        v.push_back(root->val);
        preorderTraversalRecursive(root->left);
        preorderTraversalRecursive(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> s;
        if(root==NULL) return {};
        
        v.clear();
        
        s.push(root);
        while(1)
        {
            if(s.empty()) return v;
            
            TreeNode* curr = s.top();
            s.pop();
            v.push_back(curr->val);
            
            if(curr->right)
            {
                s.push(curr->right);
            }
            if(curr->left)
            {
                s.push(curr->left);
            }
        }
        
    }
};