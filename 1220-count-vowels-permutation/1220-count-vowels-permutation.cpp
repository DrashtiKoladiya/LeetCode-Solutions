class Solution {
public:
    int countVowelPermutation(int n) {
        
        int dp[5][n+1],mod = 1e9+7;
        
        for(int i=0;i<5;i++)
        {
            dp[i][0]=1;
        }
        
        n--;
        for(int i=1;i<=n;i++)
        {
            dp[0][i] = dp[1][i-1];
            dp[1][i] = (dp[0][i-1] + dp[2][i-1])%mod;
            dp[2][i] = (((dp[0][i-1]+dp[1][i-1])%mod + dp[3][i-1])%mod + dp[4][i-1])%mod;
            dp[3][i] = (dp[2][i-1]+dp[4][i-1])%mod;
            dp[4][i] = dp[0][i-1];
        }
        
        return ((((dp[0][n]+dp[1][n])%mod + dp[2][n])%mod + dp[3][n])%mod + dp[4][n])%mod;
        
    }
};