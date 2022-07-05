class Solution {
public:
    vector<vector<int>> dp;
    bool dpp(int src,int sum,vector<int> &nums)
    {
        if(sum==0) return 1;
        if(sum<0 || src<0) return 0;
        
        if(dp[src][sum]!=-1) return dp[src][sum];
        
        int ans = dpp(src-1,sum-nums[src],nums);
        ans|= dpp(src-1,sum,nums);
        
        return dp[src][sum]=ans;
    }
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
        }
        
        if(sum%2) return 0;
        sum/= 2;
        dp = vector<vector<int>>(n,vector<int>(sum+1,-1));
        
        return dpp(n-1,sum,nums);
        
    }
};