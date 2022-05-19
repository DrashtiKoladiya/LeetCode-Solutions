class Solution {
public:
    set<int> Dfs(int src,vector<set<int>> &anc,vector<vector<int>> &adj)
    {
        //cout<<src<<"\n";
        if(anc[src].size()!=0) return anc[src];
        
        for(auto it:adj[src])
        {
            //cout<<src<<" "<<it<<" --- \n";
            set<int> tmp = Dfs(it,anc,adj); 
            anc[src].insert(tmp.begin(),tmp.end());
            anc[src].insert(it);
        }
        
        //cout<<src<<" "<<ans.size()<<"\n";
        
        return anc[src];
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n),ans(n);
        vector<int> inDegree(n,0);
        
        int sz = edges.size();
        for(int i=0;i<sz;i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
            inDegree[edges[i][0]]++;
        }
        
        vector<set<int>> anc(n);
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
            {
                Dfs(i,anc,adj);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            ans[i].resize(anc[i].size());
            copy(anc[i].begin(),anc[i].end(),ans[i].begin());
        }
        
        return ans;
    }
};