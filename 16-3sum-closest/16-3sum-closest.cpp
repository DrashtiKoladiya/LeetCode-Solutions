class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int curr = INT_MIN, sum=0, n=nums.size();
        
        for(int i=0;i<(n-2);i++)
        {
            int need = target - nums[i],ff=INT_MIN;
            int l = i+1, r = n-1 ;
            
            while(l<r)
            {
                if(ff==INT_MIN || abs(nums[l]+nums[r]-need)<abs(ff-need))
                {
                    ff = nums[l]+nums[r];
                }
                
                if((nums[l]+nums[r])<need) l++;
                else r--;
            }
            
            //cout<<target<<" "<<nums[i]<<" "<<need<<" "<<ff<<"\n";
            
            if(curr==INT_MIN || abs(target-curr)>abs(target-(nums[i]+ff)))
            {
                curr = nums[i]+ff;
            }
            //cout<<curr<<"\n";
        }
        
        return curr;
        
        
        
    }
};