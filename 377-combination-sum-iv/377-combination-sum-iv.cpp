class Solution {
public:
    int dp[1001];
    int go(vector<int>& a,int sum)
    {
        if(sum==0) return 1;
        if(sum<0) return 0;
        
        if(dp[sum]!=-1) return dp[sum];
        
        int ans=0;
        for(auto it:a)
        {
            ans+= go(a,sum-it);
        }
        
        return dp[sum]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        memset(dp,-1,sizeof(dp));
        
        return go(nums,target);
        
    }
};