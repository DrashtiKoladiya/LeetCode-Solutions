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
    TreeNode *build(vector<int>& p,vector<int>& i,int l1,int r1,int &l2,map<int,int> &m)
    {
        if(l1>r1) return NULL;
        
        TreeNode* newnode = new TreeNode();
        
        l2++;
        if(l1==r1)
        {
            newnode->val = i[l1];
            return newnode;
        }
        
        int id = m[p[l2]];
        newnode->val = p[l2];
        newnode->left = build(p,i,l1,id-1,l2,m);
        newnode->right = build(p,i,id+1,r1,l2,m);
        
        return newnode;
        
        
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size(),l2=-1;
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[inorder[i]]=i;
        }
        
        return build(preorder,inorder,0,n-1,l2,m);
        
    }
};