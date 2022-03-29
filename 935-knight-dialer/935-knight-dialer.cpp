class Solution {
public:
    int dp[4][3][5001];
    int MOD = 1e9+7;
    int v1[8]={+2,-2,+2,-2,+1,+1,-1,-1},v2[8]={+1,+1,-1,-1,+2,-2,+2,-2};
    int dpp(int i,int j,int n)
    {
        if(i==3 && j!=1) return 0;
        if(i<0 || j<0 || i>=4 || j>=3) return 0;
        if(n==0) return 1;
        
        if(n<0) return 0;
                
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        
        long long int ans = 0;
        
        for(int k=0;k<8;k++)
        {
            ans+= dpp(i+v1[k],j+v2[k],n-1);
            ans%= MOD;
        }
        
        
        return dp[i][j][n]=ans;
    }
    
    int knightDialer(int n) {
        
        memset(dp,-1,sizeof(dp));
        long long sum = 0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                sum+= dpp(i,j,n-1);
                sum%= MOD;
            }
        }
        
        return sum;
    }
};