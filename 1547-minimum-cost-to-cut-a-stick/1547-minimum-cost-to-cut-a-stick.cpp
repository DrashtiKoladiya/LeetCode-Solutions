class Solution {
public:
    vector<vector<int>> dp;
    int go(int i,int j, vector<int>& cuts)
    {
        if((j-i)<=1) return 0;
        
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i+1;k<j;k++)
        {
            ans = min(ans,cuts[j]-cuts[i]+ go(i,k,cuts) + go(k,j,cuts));
        }
        
        return dp[i][j]=ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        int sz = cuts.size();
        sort(cuts.begin(),cuts.end());
        dp = vector<vector<int>>(sz+1,vector<int>(sz+1,-1));
        
       return go(0,sz-1,cuts);
        
    }
};