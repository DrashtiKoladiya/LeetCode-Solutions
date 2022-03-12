class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int mx = 0,curr=0;
        
        // based on the logic of kadane's max-sum subarray algo
        // if we have range [i,j], all the elements from (i,j) will cancel out themsalves in the next step
        for(int i=1;i<n;i++)
        {
            curr= max(0,curr+(prices[i]-prices[i-1]));
            
            mx = max(mx,curr);
        }
        
        return mx;
        
    }
};