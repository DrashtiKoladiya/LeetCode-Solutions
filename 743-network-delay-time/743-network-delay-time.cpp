class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<vector<pair<int,int>>> adj(n);
        
        int sz = times.size();
        for(int i=0;i<sz;i++)
        {
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        
        q.push({0,k-1});
        vector<int> dis(n,INT_MAX),vis(n,0);
        dis[k-1]=0;
        
        while(!q.empty())
        {
            pair<int,int> x = q.top();
            q.pop();
            if(vis[x.second])
            {
                continue;
            }
            
            vis[x.second]=1;
            for(auto it:adj[x.second])
            {
                if(!vis[it.first] && ((it.second+x.first) < dis[it.first]))
                {
                    dis[it.first]=it.second+x.first;
                    q.push({dis[it.first],it.first});
                }
            }
        }
        
        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<i<<" "<<dis[i]<<"\n";
        // }
        
        int mx = *max_element(dis.begin(),dis.end());
        
        return mx==INT_MAX?-1:mx;
    
        
    }
};