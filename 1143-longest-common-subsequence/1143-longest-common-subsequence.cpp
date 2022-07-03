class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        
        int n = s1.size(), m = s2.size();
        int a[n+1][m+1];
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==0 || j==0)
                {
                    a[i][j] = (s1[i]==s2[j]);
                }
                else
                {
                    if((s1[i-1]==s2[j-1])) a[i][j] = 1 + a[i-1][j-1];
                    else a[i][j] = max(a[i-1][j], a[i][j-1]);
                }
            }
        }
        
        return a[n][m];
        
    }
};