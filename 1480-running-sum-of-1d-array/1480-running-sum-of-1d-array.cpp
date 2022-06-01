class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> runningSum(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                runningSum[i]+= runningSum[i-1];
            }
            
            runningSum[i]+= nums[i];
        }
        
        return runningSum;
        
    }
};