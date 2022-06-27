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
    TreeNode* build(vector<int>& p,vector<int>& i,int l1,int r1,int &r2,map<int,int> &m)
    {
        if(l1>r1) return NULL;
        
        TreeNode *newnode = new TreeNode();
        
        r2--;
        if(l1==r1) 
        {
            newnode->val = i[l1];
            return newnode;
        }
        
        int id = m[p[r2]];
        newnode->val = p[r2];
        newnode->right = build(p,i,id+1,r1,r2,m);
        newnode->left =  build(p,i,l1,id-1,r2,m);
        
        return newnode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> m;
        int n = inorder.size();
        int r2=n;
        
        for(int i=0;i<n;i++)
        {
            m[inorder[i]]=i;
        }
        
        return build(postorder,inorder,0,n-1,r2,m);
    }
};