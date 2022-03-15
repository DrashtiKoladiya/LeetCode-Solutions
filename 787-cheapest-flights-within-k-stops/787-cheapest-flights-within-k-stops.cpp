class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        int dp[k+2][n];
        
        for(int i=0;i<=(k+1);i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=INT_MAX;
            }
        }
        
        for(int i=0;i<=k;i++)
        {
            dp[i][src]=0;
        }
        
        int mn = INT_MAX;
        for(int i=1;i<=(k+1);i++)
        {
            for(auto it:flights)
            {
                if(dp[i-1][it[0]]!=INT_MAX)dp[i][it[1]] = min(dp[i][it[1]],dp[i-1][it[0]]+it[2]);
            }
        }
        
        if(dp[k+1][dst]!=INT_MAX) return dp[k+1][dst];
        return -1;
        
    }
};