class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        
        int n = arr.size(),ind=-1,i;
        vector<int> lis(n,1),ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<(i);j++)
            {
                if((arr[i]%arr[j])==0)
                {
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }
        
        ind = max_element(lis.begin(),lis.end()) - lis.begin();
        
        //cout<<lis[ind]<<" "<<ind<<"\n";
        
        i=ind;
        ind--;
        ans.push_back(arr[i]);
        
        while(ind>=0)
        {
            if(lis[ind]+1==lis[i] && arr[i]%arr[ind]==0)
            {
                ans.push_back(arr[ind]);
                i=ind;
                ind--;
            }
            else
            {
                ind--;
            }
        }
        
        return ans;
        
    }
};