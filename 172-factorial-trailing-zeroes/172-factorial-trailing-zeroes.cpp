class Solution {
public:
    int trailingZeroes(int n) {
        
        int cnt=0,cc=5;
        
        while(cc<=n)
        {
            cnt+= n/cc;
            cc*= 5;
        }
        
        return cnt;
        
    }
};