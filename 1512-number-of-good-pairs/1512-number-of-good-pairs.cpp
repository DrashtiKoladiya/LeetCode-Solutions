class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt=0,ans=0;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]) cnt++;
            else
            {
                ans+= (cnt)*(cnt+1)/2;
                cnt=0;
            }
        }
        
        ans+= (cnt)*(cnt+1)/2;
        
        return ans;
        
    }
};