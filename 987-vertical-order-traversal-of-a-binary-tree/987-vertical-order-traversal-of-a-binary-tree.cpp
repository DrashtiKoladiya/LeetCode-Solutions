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
    static bool comp(pair<int,int> &v1, pair<int,int> &v2)
    {
        
        if(v1.second == v2.second)
        {
            return v1.first < v2.first;
        }
          
        return v1.second < v2.second;
                
    }
    void go(TreeNode *root, map<int, vector<pair<int,int>>>& m, int level, int row)
    {
        if(root==NULL)
        {
            return;
        }
        
        m[level].push_back({root->val, row});
        go(root->left, m, level-1, row+1);
        go(root->right, m, level+1, row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, vector<pair<int,int>>> m;
        vector<vector<int>> ans;
        go(root, m, 0, 0);
        
        for(auto it=m.begin(); it!=m.end();it++)
        {
            vector<pair<int,int>> v = it->second;
            
            // for(auto it2:v)
            // {
            //     cout<<it2.first<<" "<<it2.second<<" | ";
            // }
            // cout<<"\n";
            
            sort(v.begin(),v.end(),comp);
            
            // for(auto it2:v)
            // {
            //     cout<<it2.first<<" "<<it2.second<<" | ";
            // }
            // cout<<"\n";
            
            vector<int> anslevel;
            for(auto it2:v)
            {
                anslevel.push_back(it2.first);
            }
            ans.push_back(anslevel);
        }
        
        return ans;
        
    }
};