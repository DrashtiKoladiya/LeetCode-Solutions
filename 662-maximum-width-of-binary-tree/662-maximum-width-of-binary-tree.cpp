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
    void go(TreeNode* root,int level,unsigned int order,map<int,pair<unsigned int,unsigned int>> &m)
    {
        if(root==NULL) return;
        if(!m.count(level)) m[level] = {order,order};
        else m[level].second = order;
            
        go(root->left,level+1,2*order,m);
        go(root->right,level+1,2*order+1,m);
        
    }
    int widthOfBinaryTree(TreeNode* root) {
        
        unsigned int ans=0;
        map<int,pair<unsigned int,unsigned int>> m;
        go(root,0,1,m);
        
        for(auto it:m)
        {
            ans = max(ans, it.second.second - it.second.first+1);
        }
        
        return ans;
    }
};