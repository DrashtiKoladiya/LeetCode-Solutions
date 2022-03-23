class Solution {
public:
    int dp[21][21];
    int dpp(int l,int r,vector<int>& nums)
    {
        if(l>r) return 0;
        if(l==r) return nums[l];
        
        if(dp[l][r]!=-1) return dp[l][r];
        
        int ans = INT_MIN;
        
        ans = max(ans,nums[l]-dpp(l+1,r,nums));
        ans = max(ans,nums[r]-dpp(l,r-1,nums));
        
        return dp[l][r]=ans;
    }
    bool PredictTheWinner(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        
        return dpp(0,nums.size()-1,nums)>=0;
    }
};