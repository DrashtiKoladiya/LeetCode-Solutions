class Solution {
public:
    string longestPrefix(string s) {
        /*
        // using z-algorithm
        int n = s.size();
        vector<int> z(n,0);
        int l=0,r=0;
        
        for(int i=1;i<n;i++)
        {
            if(i<=r)
            {
                z[i]=min(r-i+1,z[i-l]);
            }
            
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
            
            if(z[i] == (n-i)) return s.substr(i,z[i]);
            
            if((i+z[i]-1)>r)
            {
                l=i;
                r=i+z[i]-1;
            }

        }
        
        return "";
        */
        
        // using kmp algorithm
        int n = s.size(),i=0,j=1;
        vector<int> lps(n,0);
        
        while(j<n)
        {
            if(s[i]==s[j])
            {
                i++;
                lps[j]=i;
                j++;
            }
            else
            {
                if(i!=0)
                {
                    i=lps[i-1];
                }
                else
                {
                    j++;
                }
            }
        }
        
        return s.substr(0,lps[n-1]);
        
    }
};