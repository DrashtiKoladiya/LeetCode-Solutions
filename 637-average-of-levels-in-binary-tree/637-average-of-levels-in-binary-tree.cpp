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
    void dfs(TreeNode* root, double level, vector<vector<double>> &v)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(v[0].size() == (int)level)
        {
            v[0].push_back(0);
            v[1].push_back(0);
        }
        
        v[0][level]+= (root->val);
        v[1][level]+= (double)1;
        
        dfs(root->left, level+1, v);
        dfs(root->right, level+1, v);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<vector<double>> v(2);
        
        dfs(root,0,v);
        
        int sz = v[0].size();
        for(int i=0;i<sz;i++)
        {
            v[0][i] = v[0][i]/v[1][i]; 
        }
       
        return v[0];    
        
    }
};