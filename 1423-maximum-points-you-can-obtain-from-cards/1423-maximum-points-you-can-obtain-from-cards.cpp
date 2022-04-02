class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int sum = 0;
        
        for(int i=1;i<n;i++)
        {
            cardPoints[i]+= cardPoints[i-1];
        }
        
        if(k==n) return cardPoints[n-1];
        
        for(int i=0;i<k;i++)
        {
            int tmp = (n-1) - (k-(i+1));
            int backSum = cardPoints[n-1] - cardPoints[tmp];
            
            sum = max(sum,cardPoints[i]+backSum);
        }
        
        sum = max(sum,cardPoints[n-1]-cardPoints[n-1-k]);
        
        return sum;
        
    }
};