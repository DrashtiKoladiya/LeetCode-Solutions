class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size(),i=1;
        for(;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                break;
            }
        }
        
        if(i==n)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        
        i=n-1;
        for(;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                sort(nums.begin()+i,nums.end());
                
                int id = upper_bound(nums.begin()+i,nums.end(),nums[i-1])-nums.begin();
                swap(nums[id],nums[i-1]);
                break;
            }
        }     
    }
};