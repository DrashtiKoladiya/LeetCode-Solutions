class Solution {
public:
    int dp[101][101][601];
    int dpp(vector<pair<int,int>> &cnt,int src,int m,int n)
    {
        if(src==cnt.size())
        {
            return 0;
        }
        
        if(dp[m][n][src]!=-1) return dp[m][n][src];
        
        int ans = INT_MIN;
        
        if((m-cnt[src].first)>=0 && (n-cnt[src].second)>=0)
        {
            ans = max(ans,dpp(cnt,src+1,m-cnt[src].first,n-cnt[src].second)+1);
        }
        
        ans = max(ans,dpp(cnt,src+1,m,n));
        
        return dp[m][n][src]=ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>> cnt;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<strs.size();i++)
        {
            int cnt0=0,cnt1=0;
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j]=='0') cnt0++;
                else cnt1++;
            }
            
            cnt.push_back({cnt0,cnt1});
            //cout<<cnt0<<" "<<cnt1<<"\n";
        }
        
        return dpp(cnt,0,m,n);
        
    }
};