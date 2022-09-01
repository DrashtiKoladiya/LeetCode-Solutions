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
    int goodNodes(TreeNode* root,int val=INT_MIN) {
        
        if(root==NULL)
        {
            return 0;
        }
        
        int sum = 0;
        if(val<=(root->val)) sum++;
        
        val = max(val, root->val);

        
        int left = goodNodes(root->left, val);
        int right = goodNodes(root->right, val);
        
        sum+= (left+right);
        
        return sum;
    }
};