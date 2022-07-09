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
    TreeNode* go(vector<int> &preorder, int i,int j, vector<int>& nextg)
    {
        if(i>j) return NULL;
        
        TreeNode *curr = new TreeNode(preorder[i]);
        if(i==j) return curr;
        
        TreeNode *left, *right;
        left = go(preorder,i+1,min(j,nextg[i]-1),nextg);
        right = go(preorder, nextg[i], j, nextg);
        
        curr->left = left;
        curr->right = right;
        
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n = preorder.size();
        vector<int> nextg(n,INT_MAX);
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && preorder[s.top()] < preorder[i])
            {
                int tmpid = s.top();
                s.pop();
                nextg[tmpid] = i;
            }
            
            s.push(i);
        }
        
        //return NULL;
        
        return go(preorder,0,n-1,nextg);
        
    }
};