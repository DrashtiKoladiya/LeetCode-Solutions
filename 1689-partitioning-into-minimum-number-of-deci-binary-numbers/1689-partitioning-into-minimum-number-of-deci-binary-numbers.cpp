class Solution {
public:
    int minPartitions(string s) {
        
        int mx = 0;
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            mx = max(mx, s[i]-'0');
        }
        
        return mx;
        
    }
};