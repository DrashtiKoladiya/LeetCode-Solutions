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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        int level = 0;
        
        if(root==NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                TreeNode *curr;
                curr = q.front();
                q.pop();
                
                if(ans.size()==level) ans.push_back({});
                
                ans[level].push_back(curr->val);
                
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);      
            }
            if(level%2) reverse(ans[level].begin(),ans[level].end());
            level++;
        }
        
        return ans;
        
    }
};