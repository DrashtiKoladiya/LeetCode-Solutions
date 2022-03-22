class Solution {
public:
    int dp(int n)
    {
        if(n==0) return 1;
        
        if(n==1) return 10;
        
        int ans = dp(n-1);
        
        int tmp = 9,ans1=9;
        while(--n)
        {
            ans1*= tmp;
            tmp--;
        }
        
        return ans+ans1;
    }
    int countNumbersWithUniqueDigits(int n) {
        
        return dp(n);
        
    }
};