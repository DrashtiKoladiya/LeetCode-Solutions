class Solution {
public:
    vector<int> ans;
    void generateNumber(int currDigit, int k, int n, int num)
    {
        if(n<=0)
        {
            ans.push_back(num);
            return;
        }
        
        n--;
        if(currDigit-k >= 0)
        {
            generateNumber(currDigit-k, k, n, num*10 + (currDigit-k));
        }
        
        if((currDigit+k) <= 9 && k!=0)
        {
            generateNumber(currDigit+k, k, n, num*10 + (currDigit+k));
        }
            
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        
        ans.clear();
        for(int i=1;i<=9;i++)
        {
            generateNumber(i, k, n-1, i);
        }
        
        return ans;
    }
};