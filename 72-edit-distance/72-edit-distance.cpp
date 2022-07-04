class Solution {
public:
    vector<vector<int>> dp;
    int go(int i,int j,vector<vector<int>> &dp,string &word1, string &word2)
    {
        if(i<0 && j<0) return 0;
        
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = INT_MAX;
        if(word1[i]==word2[j])
        {
            ans = go(i-1,j-1,dp,word1,word2);
        }
        else
        {
            ans = go(i-1,j-1,dp,word1,word2);
            ans = min(ans,go(i,j-1,dp,word1,word2));
            ans = min(ans,go(i-1,j,dp,word1,word2));
            ans++;
        }
        
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        
        dp = vector<vector<int>>(n,vector<int>(m,-1));
        
        return go(n-1,m-1,dp,word1,word2);
        
    }
};