class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int mx = 0;
        
        int i=0;
        // velly- mountain pattern
        while(i<n)
        {
            // finding the peak element
            int j = i;
            while(j<(n-1) && prices[j]<=prices[j+1])
            {
                j++;
            }
        
            mx+= (prices[j]-prices[i]);
            
            i = j+1;
        }
        
        return mx;
        
    }
};