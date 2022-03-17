class Solution {
public:
    bool issorted(vector<int> &nums)
    {
        int prev=-1,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==-1) continue;
            
            if(prev==-1)
            {
                prev=nums[i];
                continue;
            }
            
            if(nums[i]<=prev) return 0;
            
            prev=nums[i];
        }
        
        return 1;
    }
    bool canBeIncreasing(vector<int>& nums) {
        
        int i1=-1,i2=-1,n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
            {
                i1=i-1;
                i2=i;
                break;
            }
        }
        
        if(i1==-1) return 1;
        
        int tmp;
        tmp = nums[i1],nums[i1]=-1;
        if(issorted(nums)) return 1;
        nums[i1]=tmp,tmp=nums[i2],nums[i2]=-1;
        if(issorted(nums)) return 1;
        
        return 0;
    }
};