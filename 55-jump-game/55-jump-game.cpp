class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int sz = nums.size()-1;
        int mxindex = 0;
        for(int i=0;i<sz;i++)
        {
            if(mxindex>=i) 
            {
                mxindex = max(mxindex, i+nums[i]);
            }
        }
        
        if(mxindex >= sz) return 1;
        return 0;
    }
};