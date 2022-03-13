class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        if(n<=2) return ans;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<(n-2);i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
            {
                continue;
            }
            
            int sum = -nums[i];
            int l = i+1, r=n-1;
            
            while(l<r)
            {
                if((nums[l]+nums[r])<sum)
                {
                    l++;
                }
                else if((nums[l]+nums[r])>sum)
                {
                    r--;
                }
                else
                {
                    if(l!=0 && r!=(n-1) && nums[l]==nums[l-1] && nums[r]==nums[r+1])
                    {
                        l++,r--;
                        continue;
                    }
                        
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++,r--;
                }
            }
        }
        
        return ans;
        
    }
};