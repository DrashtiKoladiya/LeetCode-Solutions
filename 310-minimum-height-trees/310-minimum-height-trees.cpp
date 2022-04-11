class Solution {
public:
    vector<vector<int>> adj;
    int mx,first,second,tmp;
    vector<int> v;
    void dfs1(int src,int height,int par)
    {
       for(auto it:adj[src])
       {
          if(it!=par)
          {
              dfs1(it,height+1,src);
          }
       }
        
       if(height>mx)
       {
           mx = height;
           tmp = src;
       }
    }
    
    void dfs2(int src,int height,int par,vector<int> &s)
    {
        for(auto it:adj[src])
        {
            if(it!=par)
            {
                s.push_back(it);
                dfs2(it,height+1,src,s);
                s.pop_back();
            }
        }
        
        if(src==second)
        {
            v = s;
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        adj = vector<vector<int>>(n);
        v.clear();
        first=-1,second=-1,mx=0;
        
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        mx = 0;
        dfs1(0,1,-1);
        
        //cout<<mx<<" "<<first<<" "<<second<<"\n";

        
        first = tmp;
        mx=0;
        dfs1(first,1,-1);
        second = tmp;
        vector<int> hehe = {first};
        
        //cout<<mx<<" "<<first<<" "<<second<<"\n";
        
        dfs2(first,1,-1,hehe);
        
        if(mx%2==0) return {v[mx/2],v[(mx-1)/2]};
        
        return {v[mx/2]};
        
        
        
    }
};