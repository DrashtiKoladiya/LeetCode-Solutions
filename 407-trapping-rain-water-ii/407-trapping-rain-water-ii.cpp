class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        if(heightMap.size()==0) return 0;
        
        int n = heightMap.size(),m = heightMap[0].size(),trappedWater=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> p;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++)
        {
            vis[0][i]=1, vis[n-1][i]=1;
            p.push({heightMap[0][i],0,i});
            p.push({heightMap[n-1][i],n-1,i});
        }
        
        for(int i=1;i<(n-1);i++)
        {
            vis[i][0]=1, vis[i][m-1]=1;
            p.push({heightMap[i][0],i,0});
            p.push({heightMap[i][m-1],i,m-1});
        }
        
        while(!p.empty())
        {
            vector<int> a = p.top();
            p.pop();
            
            if((a[1]-1)>=0 && !vis[a[1]-1][a[2]])
            {
                vis[a[1]-1][a[2]]=1;
                trappedWater+= max(0,a[0]-heightMap[a[1]-1][a[2]]);
                p.push({max(heightMap[a[1]-1][a[2]],a[0]),a[1]-1,a[2]});
            }
            if((a[1]+1)<n && !vis[a[1]+1][a[2]])
            {
                vis[a[1]+1][a[2]]=1;
                trappedWater+= max(0,a[0]-heightMap[a[1]+1][a[2]]);
                p.push({max(heightMap[a[1]+1][a[2]],a[0]),a[1]+1,a[2]});
            }
            if((a[2]-1)>=0 && !vis[a[1]][a[2]-1])
            {
                vis[a[1]][a[2]-1]=1;
                trappedWater+= max(0,a[0]-heightMap[a[1]][a[2]-1]);
                p.push({max(heightMap[a[1]][a[2]-1],a[0]),a[1],a[2]-1});
            }
            if((a[2]+1)<m && !vis[a[1]][a[2]+1])
            {
                vis[a[1]][a[2]+1]=1;
                trappedWater+= max(0,a[0]-heightMap[a[1]][a[2]+1]);
                p.push({max(heightMap[a[1]][a[2]+1],a[0]),a[1],a[2]+1});
            }
            
        }
        
        return trappedWater;
        
    }
};