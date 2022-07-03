class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        int a[n][n];
        int i1=0,j=0;
        
        memset(a,-1,sizeof(a));
        for(int i=0;i<n;i++)
        {
            a[i][i]=1;
            if(i!=0)
            {
                if(s[i]==s[i-1])
                {
                    if(2 > (j-i1+1))
                    {
                        i1=i-1;
                        j=i;
                    }
                    a[i-1][i]=1;
                }
            }
        }
        
        for(int sz=3;sz<=n;sz++)
        {
            for(int i=0;i<(n-sz+1);i++)
            {
                if(s[i]==s[i+sz-1] && a[i+1][i+sz-2]==1)
                {
                    if(((i+sz-1)-i+1) > (j-i1+1))
                    {
                        i1 = i;
                        j = i+sz-1;
                    }
                    a[i][i+sz-1] = 1;
                }
            }
        }
        
    
        
        return s.substr(i1,j-i1+1);
        
    }
};