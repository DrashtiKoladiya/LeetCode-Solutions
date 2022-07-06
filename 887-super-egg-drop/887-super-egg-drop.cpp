class Solution {
public:
    int superEggDrop(int k, int n) {
        
        int dp[k+1][n+1];
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j] = INT_MAX;
            }
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<=k;j++)
            {
                dp[j][i]=i;
            }
        }
        
        for(int i=0;i<=n;i++)
        {
            dp[1][i]=i;
        }
        
        for(int e=2;e<=k;e++)
        {
            for(int f=2;f<=n;f++)
            {
                int l = 1, r = f;
                while((r-l)>=2)
                {
                    int mid = r + (l-r)/2;
                    if(dp[e-1][mid-1] > dp[e][f-mid]) r = mid;
                    else if(dp[e-1][mid-1] < dp[e][f-mid]) l = mid;
                    else
                    {
                        l=mid,r=mid;
                    }
                }
                dp[e][f] = 1 + min(max(dp[e-1][l-1],dp[e][f-l]),max(dp[e-1][r-1],dp[e][f-r]));
            }
        }
        
        return dp[k][n];
        
    }
};