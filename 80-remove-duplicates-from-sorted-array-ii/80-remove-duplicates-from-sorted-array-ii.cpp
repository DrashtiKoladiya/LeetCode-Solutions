class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size(), l=0;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {
                if(l==0 || nums[l]!=nums[l-1])
                {
                    l++;
                    nums[l]=nums[i];
                }
            }
            else
            {
                l++;
                nums[l]=nums[i];
            }
        }
        
        return l+1;
        
    }
};