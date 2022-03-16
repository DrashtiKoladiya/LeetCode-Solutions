class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> m;
        int n=nums.size();
        
        int l=0,r=n-1;
        for(int i=0;i<n;i++)
        {
            if(m.count(target-nums[i]))
            {
                return {m[target-nums[i]],i};
            }
            
            m[nums[i]]=i;
        }
        
        return {-1,-1};
        
    }
};