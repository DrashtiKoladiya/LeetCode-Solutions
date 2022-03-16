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
        
        cSum(arr,target,i+1,ans1);
        
        ans1.push_back(arr[i]);
        cSum(arr,target-arr[i],i,ans1);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        
        ans.clear();
        vector<int> ans1;
        cSum(arr,target,0,ans1);
        
        return ans;
        
    }
};