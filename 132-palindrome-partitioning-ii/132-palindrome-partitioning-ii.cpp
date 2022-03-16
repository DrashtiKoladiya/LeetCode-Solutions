class Solution {
public:
    int minCut(string s) {
        
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
        
        int mincut[n+1];
        mincut[0]=-1;
        mincut[1]=0;
        for(int i=2;i<=n;i++)
        {
            mincut[i]=i-1;
            for(int j=1;j<=i;j++)
            {
                if(dp[j-1][i-1]==1)
                {
                    mincut[i]=min(mincut[i],mincut[j-1]+1);
                }
            }
        }
        
        return mincut[n];
        
    }
};