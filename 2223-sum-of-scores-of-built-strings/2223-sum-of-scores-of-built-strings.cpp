class Solution {
public:
    long long sumScores(string s) {
        
        long long int sum = 0;
        int n = s.size();
        vector<int> z(n,0);
        z[0]=n;
        int l=0,r=0;
        
        for(int i=1;i<n;i++)
        {
            if(i<=r) 
            {
                z[i]=min((r-i+1),z[i-l]);
            }
            
            while(i+z[i]<n && s[z[i]]==s[i+z[i]])
            {
                z[i]++;
            }
            
            if((i+z[i]-1)>r)
            {
                l=i;
                r=i+z[i]-1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            sum+= z[i];
        }
        
        return sum;
    }
};