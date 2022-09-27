class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return 0;
        
        int stepsLeft=nums[0], mxPosition=nums[0], minJumps=1;
        
        for(int i=1;i<(n-1);i++)
        {
            if(mxPosition >= i)
            {
                mxPosition = max(mxPosition, i+nums[i]);
            }
            
            stepsLeft--;
            //cout<<stepsLeft<<" "<<mxPosition<<" "<<i<<"\n";
            
            if(stepsLeft==0 && mxPosition>i)
            {
                minJumps++;
                stepsLeft = mxPosition-i;
            }
        }
        
        return minJumps;
        
    }
};