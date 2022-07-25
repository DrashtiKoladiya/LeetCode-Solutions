class Solution {
public:
    void merge(vector<pair<int,int>> &nums,int l,int mid, int r,vector<int> &ans)
    {
        int sz = r-l+1,cnt=0;
        vector<pair<int,int>> tmp(sz);
        int i=l,j=mid+1,k=0;
        
        while(i<=mid && j<=r)
        {
            if(nums[i].first <= nums[j].first)
            {
                tmp[k] = nums[i];
                ans[nums[i].second]+= cnt;
                i++;
            }
            else
            {
                tmp[k] = nums[j];
                cnt++;
                j++;
                
            }
            k++;
        }
        
        while(i<=mid)
        {
            tmp[k] = nums[i];
            ans[nums[i].second]+= cnt;
            k++,i++;
        }
        
        while(j<=r)
        {
            tmp[k] = nums[j];
            k++,j++;
        }
        
        k=0;
        for(int i=l;i<=r;i++)
        {
            nums[i]=tmp[k];
            k++;
        }
        
    }
    void mergeSort(int l,int r,vector<pair<int,int>> &nums,vector<int> &ans) 
    {
        if(l>=r)
        {
            return;
        }
        
        int mid = l + (r-l)/2;
        
        mergeSort(l,mid,nums,ans);
        mergeSort(mid+1,r,nums,ans);
        merge(nums,l,mid,r,ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<int,int>> v(n);
        
        for(int i=0;i<n;i++)
        {
            v[i].first = nums[i];
            v[i].second = i;
        }

        vector<int> ans(n,0);
        
        mergeSort(0,n-1,v,ans);
        
        return ans;
        
    }
};