class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int dp[2][n2+1], ans=0;
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i%2][j]=0;
                }
                else if(nums1[i-1]==nums2[j-1])
                {
                    dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
                    ans = max(ans, dp[i%2][j]);
                }
                else
                {
                    dp[i%2][j] = 0;
                }
            }
        }
        
        return ans;
        
    }
};