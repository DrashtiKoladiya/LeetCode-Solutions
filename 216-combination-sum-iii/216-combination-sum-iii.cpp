class Solution {
public:
    vector<vector<int>> ans;
    void cSum(int k,int n,vector<int> ans1,int i)
    {
        if(k==0)
        {
            if(n==0)
            {
                ans.push_back(ans1);
            }
            return;
        }
        
        if(i==10 || n<0) return;
        
        cSum(k,n,ans1,i+1);
        
        ans1.push_back(i);
        cSum(k-1,n-i,ans1,i+1);
        //ans1.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        ans.clear();
        vector<int> ans1;
        cSum(k,n,ans1,1);
        
        return ans;
        

        
    }
};