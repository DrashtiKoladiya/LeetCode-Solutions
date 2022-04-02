class Solution {
public:
    int dp[1001][1001];
    int dpp(vector<int> &a,vector<int> &b,int i,int j)
    {
        if(i>=b.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = 0;
        int r = a.size()-1-(i-j);
        ans = max(a[j]*b[i]+dpp(a,b,i+1,j+1),a[r]*b[i]+dpp(a,b,i+1,j));
        
        return dp[i][j]=ans;
    }
    int maximumScore(vector<int>& nums, vector<int>& multiplier) {  
        
        memset(dp,-1,sizeof(dp));
        return dpp(nums,multiplier,0,0);
        
    }
};