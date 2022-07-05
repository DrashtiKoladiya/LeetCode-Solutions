class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ans = INT_MAX;
                if((i-1)>=0)
                {
                    ans = min(ans, grid[i-1][j]);
                }
                if((j-1)>=0)
                {
                    ans = min(ans, grid[i][j-1]);
                }
                
                if(ans==INT_MAX) ans=0;
                
                grid[i][j]+= ans;
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        return grid[n-1][m-1];
        
    }
};