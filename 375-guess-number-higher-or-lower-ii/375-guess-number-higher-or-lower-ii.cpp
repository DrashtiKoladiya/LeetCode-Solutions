class Solution {
public:
    int dp[201][201];
    int dpp(int i,int j)
    {
        if(i>=j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i;k<=j;k++)
        {
            ans = min(ans,max(dpp(i,k-1)+k,dpp(k+1,j)+k));
        }
        
        return dp[i][j]=ans;
    }
    int getMoneyAmount(int n) {
        
        memset(dp,-1,sizeof(dp));
        
        return dpp(1,n);
        
    }
};