class Solution {
public:
    set<vector<int>> s;
    
    void findSubs(vector<int>& nums,int i,int n,vector<int> v)
    {
        if(i==n)
        {
            s.insert(v);
            return;
        }
        
        findSubs(nums,i+1,n,v);
        v.push_back(nums[i]);
        findSubs(nums,i+1,n,v);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        s.clear();
        vector<int> v;
        findSubs(nums,0,nums.size(),v);
        
        vector<vector<int>> ans;
        for(auto it:s)
        {
            ans.push_back(it);
        }
        
        return ans;
        
    }
};