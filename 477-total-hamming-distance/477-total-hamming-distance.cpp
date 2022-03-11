class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        vector<int> bits(32,0);
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<32;j++)
            {
                if((nums[i]>>j)&1) bits[j]++;
            }
        }
        
        int ans = 0;
        for(int i=0;i<32;i++)
        {
            ans+= (bits[i]*(n-bits[i]));
        }
        
        return ans;
        
    }
};