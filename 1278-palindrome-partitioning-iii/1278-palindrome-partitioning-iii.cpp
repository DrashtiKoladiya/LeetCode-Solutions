class Solution {
public:
    long long int dp[101][101];
    int PalindromeAdd(string s)
    {
        int n=s.length();
        int l=0,r=n-1;
        
        int cnt=0;
        while(l<r)
        {
            if(s[l]!=s[r]) cnt++;
            l++, r--;
        }
        
        return cnt;
    }
    
    long long int dpp(string s,int i,int k)
    {  
        if(i==s.size())
        {
            if(k==0) return 0;
            else return INT_MAX;
        }
        
        if(k<=0) return INT_MAX;
        
        if(dp[i][k]!=-1) return dp[i][k];
        
        long long int ans = INT_MAX;
        
        for(int k1=i;k1<s.size();k1++)
        {
            long long int tmp = dpp(s,k1+1,k-1);
            ans = min(ans,PalindromeAdd(s.substr(i,k1-i+1))+tmp);
        }
        
        return dp[i][k]=ans;
    }
    int palindromePartition(string s, int k) {
        
        memset(dp,-1,sizeof(dp));
        
        return dpp(s,0,k);
        return 0;
    }
};