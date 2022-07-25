class Solution {
public:
    void searchElement(vector<int>& nums,int target, vector<int> &ans,int l,int r)
    {
        if(l>r) return;
        
        int mid = l+(r-l)/2;
        if(nums[mid]==target)
        {
            if(ans[0]==-1)
            {
                ans[0]=mid;
                ans[1]=mid;
            }
            else
            {
                ans[0]=min(ans[0],mid);
                ans[1]=max(ans[1],mid);
            }
            searchElement(nums,target,ans,l,mid-1);
            searchElement(nums,target,ans,mid+1,r);
        }
        else if(nums[mid]>target)
        {
            searchElement(nums,target,ans,l,mid-1);
        }
        else searchElement(nums,target,ans,mid+1,r);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        
        searchElement(nums,target,ans,0,nums.size()-1);
        return ans;
        
    }
};