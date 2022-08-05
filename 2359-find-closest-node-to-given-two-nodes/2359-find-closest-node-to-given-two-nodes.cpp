class Solution {
public:
    void dfs(int src, vector<int>& dis, int ds, vector<int>& edges)
    {
        dis[src]=ds;
        
        if(edges[src]!=-1 && dis[edges[src]]==INT_MAX)
        {
            dfs(edges[src], dis, ds+1, edges);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();
        vector<int> dis1(n,INT_MAX), dis2(n,INT_MAX);
        
        dfs(node1, dis1, 0, edges);
        dfs(node2, dis2, 0, edges);
        
        int ans = INT_MAX, ansid = -1;
        for(int i=0;i<n;i++)
        {
            int prevans = ans;
            ans = min(ans, max(dis1[i], dis2[i]));
            if(ans < prevans && ans!=INT_MAX)
            {
                ansid = i;
            }
        }
        
        return ansid;
        
        
    }
};