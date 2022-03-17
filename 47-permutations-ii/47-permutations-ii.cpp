class Solution {
public:
    vector<vector<int>> ans;
    void go(vector<int> & nums,vector<int> vis,vector<int> ans1,int cnt)
    {
        if(cnt==nums.size())
        {
            ans.push_back(ans1);
            return;
        }
        
        int prev=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(!vis[i])
            {
                if(i>0 && nums[i]==nums[i-1] && vis[i-1])
                {
                    continue;
                }
                
                ans1.push_back(nums[i]);
                vis[i]=1;
                go(nums,vis,ans1,cnt+1);
                ans1.pop_back();
                vis[i]=0;
                prev = nums[i];
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        ans.clear();
        int n = nums.size();
        vector<int> vis(n,0),ans1;
        
        go(nums,vis,ans1,0);
        
        return ans;
        
    }
};