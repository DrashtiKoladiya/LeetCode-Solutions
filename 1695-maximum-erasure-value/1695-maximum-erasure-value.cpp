class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int i=0,j=0;
        long long int sum=0,mxsum=0;
        map<int,int> m;
        
        while(j<n)
        {
            
            m[nums[j]]++;
            sum+= nums[j];
            
            while(m[nums[j]]>1)
            {
                m[nums[i]]--;
                sum-= nums[i];
                i++;
            }
              
            mxsum = max(mxsum,sum);  
            j++;
        }
        
        return mxsum;
        
    }
};