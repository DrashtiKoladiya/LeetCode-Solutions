class Solution {
public:
    double dp[200][200];
    double dpp(int a,int b)
    {
        if(a<=0 && b>0) return 1;
        if(a<=0 && b<=0) return 0.5;
        if(a>0 && b<=0) return 0;
        
        if(dp[a][b]!=-1) return dp[a][b];
        
        double ans=0;
        
        ans+= 0.25*dpp(a-4,b);
        ans+= 0.25*dpp(a-3,b-1);
        ans+= 0.25*dpp(a-2,b-2);
        ans+= 0.25*dpp(a-1,b-3);
        
        return dp[a][b]=ans;
    }
    double soupServings(int n) {
        
        if(n>5000) return 1;
        
        for(int i=0;i<200;i++)
        {
            for(int j=0;j<200;j++)
            {
                dp[i][j]=-1;
            }
        }
        return dpp(n/25+(n%25!=0),n/25+(n%25!=0));
        
    }
};