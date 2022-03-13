class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l=0,r=0,cnt=0,mx=0,n=nums.size();
        
        while(r<n)
        {
            if(nums[r]==0) cnt++;
            
            while(cnt>k)
            {
                if(nums[l]==0) cnt--;
                
                l++;
            }
            
            mx = max(mx,r-l+1);
            r++;
        }
        
        return mx;
        
    }
};