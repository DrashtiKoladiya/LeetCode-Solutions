class Solution {
public:
    int numTilings(int n) {
        
        if(n<3) return n;
        
        long long int dp[n+1][3];
        
        memset(dp,0,sizeof(dp));
        dp[0][0]=1, dp[1][0]=1, dp[1][1]=1, dp[1][2]=1;
        long long int mod = 1e9+7;
        
        for(int i=2;i<=n;i++)
        {
            dp[i][0] = (dp[i-1][0] + dp[i-2][0] + dp[i-2][1] + dp[i-2][2])%mod;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
            dp[i][2] = (dp[i-1][1] + dp[i-1][0])%mod;
        }
        
        return dp[n][0];
        
    }
};