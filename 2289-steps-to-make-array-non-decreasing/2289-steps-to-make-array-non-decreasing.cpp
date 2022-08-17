class Solution {
public:
    int totalSteps(vector<int>& nums) {
        
        int n = nums.size();
        stack<int> s;
        int mx = 0;
        vector<int> dp(n,0);
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && nums[s.top()]<nums[i])
            {
                dp[i] = max(dp[i]+1, dp[s.top()]);
                s.pop();
            }
            
            s.push(i);
            mx = max(mx, dp[i]);
        }
        
        return mx;
        
    }
};