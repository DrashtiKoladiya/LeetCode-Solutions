class Solution {
public:
    int minOperations(int n) {
        
        int sum = n + n*(n-1);
        int target = sum/n;
        
        int left = 0, right = 0;
        for(int i=0;i<n;i++)
        {
            if((2*i + 1) <= target)
            {
                left+= (target - (2*i + 1));
            }
            else
            {
                right+= ((2*i + 1) - target);
            }
        }
        
        //cout<<left<<" "<<right<<"\n";
        return left;
        
    }
};