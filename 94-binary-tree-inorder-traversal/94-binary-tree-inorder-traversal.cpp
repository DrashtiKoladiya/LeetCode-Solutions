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
    void go(TreeNode* root)
    {
        if(root==NULL) return;
        
        go(root->left);
        v.push_back(root->val);
        go(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        v.clear();
        TreeNode* curr = root;
        while(curr)
        {
            if(curr->left==NULL)
            {
                v.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode* prev = curr->left;
                while(prev->right!=curr && prev->right!=NULL)
                {
                    prev = prev->right;
                }
                
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    curr=curr->left;
                }
                else
                {
                    v.push_back(prev->right->val);
                    curr = prev->right->right;
                    prev->right=NULL;
                    
                }
                
            }
        }
        
        return v;
        
    }
};