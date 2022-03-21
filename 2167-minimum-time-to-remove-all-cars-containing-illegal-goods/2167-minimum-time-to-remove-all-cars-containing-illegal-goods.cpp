class Solution {
public:
    int minimumTime(string s) {
        
        int n=s.size();
        int i,j,numo=0,left=0,ans=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                left = min(left+2,i+1);   
                ans = min(ans,left+n-i-1);
            }
            else
            {
                left = min(left,i+1);
                ans = min(ans,left+n-i-1);
            }
        }
        
        return ans;
        
    }
};