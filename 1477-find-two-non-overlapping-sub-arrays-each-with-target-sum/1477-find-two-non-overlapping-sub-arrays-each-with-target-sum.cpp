class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size(),ans=INT_MAX,sum=0;
        int prefix[n+1];
        prefix[0]=INT_MAX;
        
        map<int,int> m;
        m[0]=-1;
        for(int i=0;i<n;i++)
        {
            sum+= arr[i];
            
            prefix[i+1]=prefix[i];
            if(m.count(sum-target))
            {
                prefix[i+1]=min(prefix[i+1],i-m[sum-target]);
            }
            
            m[sum]=i;
        }
        
        m.clear();
        m[0]=n;
        int suff = INT_MAX;
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            sum+= arr[i];
            
            if(m.count(sum-target))
            {
                suff = min(suff,m[sum-target]-i);
            }
            
            m[sum]=i;
            
            if(prefix[i]!=INT_MAX && suff!=INT_MAX) ans = min(ans,suff+prefix[i]);
        }
        
        return ans==INT_MAX?-1:ans;
        
    }
};