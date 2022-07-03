class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> s;
        int n = nums.size(),mx = 1;
        s.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            int tmp = *s.rbegin();
            
            if(tmp < nums[i])
            {
                s.push_back(nums[i]);
            }
            else
            {
                auto it = lower_bound(s.begin(),s.end(),nums[i]);
                *it = nums[i];
            }
            
            mx = max(mx,(int)s.size());
        }
        
        return mx;
        
    }
};