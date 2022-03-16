class Solution {
public:
    vector<vector<int>> ans;
    void cSum(vector<int> &arr,int target,int i,vector<int> ans1)
    {
        if(target==0)
        {
            ans.push_back(ans1);
            return;
        }
        
        if(i==arr.size() || target<0)
        {
            return;
        }
        
        //cSum(arr,target,i+1,ans1);
        
        for(int j=i;j<arr.size();j++)
        {
            if(j==i || (j>i && arr[j]!=arr[j-1]))
            {
                ans1.push_back(arr[j]);
                cSum(arr,target-arr[j],j+1,ans1);
                ans1.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        
        sort(arr.begin(),arr.end());
        
        ans.clear();
        vector<int> ans1;
        cSum(arr,target,0,ans1);
        
        return ans;
        
    }
};