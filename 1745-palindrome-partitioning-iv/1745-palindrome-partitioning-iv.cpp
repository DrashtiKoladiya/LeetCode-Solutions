class Solution {
public:
    bool checkPartitioning(string s) {
        
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<n;i++) 
        {
            dp[i][i]=1;
            if(i!=0 && s[i]==s[i-1])
            {
                dp[i-1][i]=1;
            }
        }
        
        for(int i=3;i<=n;i++)
        {
            for(int j=0;(j+i-1)<n;j++)
            {
                if(dp[j+1][j+i-2]==1 && s[j]==s[j+i-1])
                {
                    dp[j][j+i-1]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                //cout<<dp[i][j]<<" ";
            }
            //cout<<"\n";
        }
        
        for(int i=0;i<(n-2);i++)
        {
            for(int j=i+1;j<(n-1);j++)
            {
                if(dp[0][i]==1 && dp[i+1][j]==1 && dp[j+1][n-1]==1) return 1;
            }
        }
        
        return 0;
        
    }
};