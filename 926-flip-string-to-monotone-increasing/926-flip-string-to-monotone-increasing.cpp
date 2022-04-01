class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int n = s.length();
        int pre[n];
        
        pre[0] = s[0]=='0' ? 0 : 1;
        
        for(int i=1; i<n; i++)
        {
            if(s[i]=='0')
            {
                pre[i] = pre[i-1];
            }
            else
            {
                pre[i] = pre[i-1]+1;
            }
        }
        
        int mini = INT_MAX;
        
        for(int i=0; i<n; i++)
        {
            int zeroBefore = pre[i];
            
            int oneAfter = n-i-1 - (pre[n-1]-pre[i]);
            
            mini = min(mini,zeroBefore+oneAfter);
        }
        
        return min(mini,min(n-pre[n-1],pre[n-1]));
        
    }
};