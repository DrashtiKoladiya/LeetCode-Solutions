class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int l=0,r=n-1,ans=nums[0];
        
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            
            ans = min(ans,nums[mid]);
            if(nums[r]>nums[mid])
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        
        return ans;
        
    }
};