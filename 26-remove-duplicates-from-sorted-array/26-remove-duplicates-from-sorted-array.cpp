class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int l=0, n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==nums[l]) continue;
            
            l++;
            nums[l] = nums[i];
        }
        
        return l+1;
        
    }
};