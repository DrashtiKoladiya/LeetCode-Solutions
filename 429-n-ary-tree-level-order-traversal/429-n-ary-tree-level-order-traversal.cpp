/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node *root, int level, vector<vector<int>> &ans)
    {
        if(root==NULL) return;
        
        if(ans.size()==level)
        {
            ans.push_back({});
        }
        
        ans[level].push_back(root->val);
        
        for(auto it:root->children)
        {
            dfs(it, level+1, ans);
        }
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        
        return ans;
        
    }
};