class Solution {
public:
    int dp[302][302];
    int dpp(int l,int r,vector<int> &nums)
    {
        if(l>r) return 0;
        if(l==r)
        {
            return  nums[l+1]*nums[l]*nums[l-1];
        }
        
        if(dp[l][r]!=-1) return dp[l][r];
        
        int ans = INT_MIN;
        
        for(int i=l;i<=r;i++)
        {
            ans = max(ans,nums[l-1]*nums[i]*nums[r+1]+dpp(l,i-1,nums)+dpp(i+1,r,nums));
        }
        
        return dp[l][r]=ans;
        
    }
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        memset(dp,-1,sizeof(dp));
        
        return dpp(1,nums.size()-2,nums);
        
        
    }
};