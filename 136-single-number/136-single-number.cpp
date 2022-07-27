class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        int element = 0;
        
        for(int i=0;i<n;i++)
        {
            element^= nums[i];
        }
        
        return element;
        
    }
};