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
    int ans1 = 0;
    vector<int> go(TreeNode *root)
    {
        if(root==NULL) return {0,0,0};
        
        //if(root->left==NULL && root->right==NULL) return {root->val,root->val,root->val};
        
        vector<int> x1 = go(root->left);
        vector<int> x2 = go(root->right);
        vector<int> ans(3,0);
        ans[0]=root->val,ans[1]=root->val,ans[2]=root->val;
        
        if(x1[0]==INT_MIN || x2[0]==INT_MIN) return {INT_MIN,-1,-1};
        
        if((root->left!=NULL))
        {
            ans[1] = max(ans[1],x1[1]);
            ans[2] = min(ans[2],x1[2]);
            if(x1[1] < root->val)
            {
                ans[0]+= x1[0];
            }
            else
            {
                return {INT_MIN,-1,-1};
            }
        }
        
        if(root->right!=NULL)
        {
            ans[2]=min(ans[2],x2[2]);
            ans[1]=max(ans[1],x2[1]);
            if(x2[2] > root->val)
            {
                ans[0]+= x2[0];
            }
            else
            {
                return {INT_MIN,-1,-1};
            }
        }
        
        
        ans1= max(ans1,ans[0]);
        return ans;
        
        
    }
    int maxSumBST(TreeNode* root) {
        
        go(root);
        return ans1;
    }
};