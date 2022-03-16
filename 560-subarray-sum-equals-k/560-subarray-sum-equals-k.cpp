class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> m;
        m[0]++;
        
        int n=nums.size();
        int cnt=0,sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
            //cout<<sum<<" "<<k-sum<<" "<<m[k-sum]<<"\n";
            if(m[sum-k]>0)
            {
                cnt+= m[sum-k];
                //cout<<"why\n";
            }
            
            m[sum]++;
        }
        
        return cnt;
        
    }
};