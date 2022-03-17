class Solution {
public:
    vector<vector<int>> ans;
    void go(vector<int>& nums,vector<int> vis,vector<int> ans1,int cnt)
    {
        if(cnt==nums.size())
        {
            ans.push_back(ans1);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                ans1.push_back(nums[i]);
                go(nums,vis,ans1,cnt+1);
                ans1.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        ans.clear();
        int n = nums.size();
        vector<int> vis(n,0),ans1;
        
        go(nums,vis,ans1,0);
        
        return ans;
        
    }
};