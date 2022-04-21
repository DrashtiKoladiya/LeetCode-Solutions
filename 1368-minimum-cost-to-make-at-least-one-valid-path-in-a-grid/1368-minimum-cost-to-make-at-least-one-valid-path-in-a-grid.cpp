class Solution {
public:
    int dpp[101][101];
    void dp(int i,int j,int n,int m,vector<vector<int>> &a,queue<pair<int,int>> &q,int level)
    {
        if(i>=n || j>=m || i<0 || j<0 || dpp[i][j]!=-1) return;
        
        dpp[i][j] = level;
        q.push({i,j});

        if(a[i][j]==1)
        {
            dp(i,j+1,n,m,a,q,level);
        }
        else if(a[i][j]==2)
        {
            dp(i,j-1,n,m,a,q,level);
        }
        else if(a[i][j]==3)
        {
            dp(i+1,j,n,m,a,q,level);
        }
        else
        {
            dp(i-1,j,n,m,a,q,level);
        }

    }
    int minCost(vector<vector<int>>& grid) {
        
        memset(dpp,-1,sizeof(dpp));
        int n,m,level=0;
        n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        
        dp(0,0,n,m,grid,q,level);
        
        while(!q.empty())
        {
            level++;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                pair<int,int> tt = q.front();
                q.pop();
                
                dp(tt.first+1,tt.second,n,m,grid,q,level);
                dp(tt.first-1,tt.second,n,m,grid,q,level);
                dp(tt.first,tt.second+1,n,m,grid,q,level);
                dp(tt.first,tt.second-1,n,m,grid,q,level);
            }
        }
        
        return dpp[n-1][m-1];
    }        
};