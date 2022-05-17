class Solution {
public:
    long long int dis(int x1,int y1,int x2,int y2)
    {
        return pow((x1-x2),2)+pow((y1-y2),2);
    }
    
    void dfs(int src,vector<vector<int>>& adj,vector<int>&vis,int &cnt)
    {
        vis[src]=1;
        cnt++;
        for(auto it:adj[src])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,cnt);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                
                if(dis(bombs[i][0],bombs[i][1],bombs[j][0],bombs[j][1]) <= pow(bombs[i][2],2))
                {
                    adj[i].push_back(j);
                }
            }
        }
        
        int mx=1;
        
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            dfs(i,adj,vis,cnt);
            mx=max(mx,cnt);
            fill(vis.begin(),vis.end(),0);
        }
        
        
        return mx;
        
    }
};