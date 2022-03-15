class Solution {
public:
    // diffrent approaches
    // https://medium.com/gitconnected/4-different-ways-to-solve-trapping-rain-water-problem-c69c09e4f96b
    int trap(vector<int>& height) {
        
        int n = height.size();
        int mx=0,mxid=-1;
        
        for(int i=0;i<n;i++)
        {
            if(height[i]>=mx)
            {
                mx = height[i];
                mxid = i;
            }
        }
        
        int trappedWater=0,cnt=height[0],count=1;
        mx = height[0];
        for(int i=1;i<=mxid;i++)
        {
            if(height[i]<mx)
            {
                cnt+= height[i];
                count++;
            }
            else
            {
                trappedWater+= (count*mx) - cnt;
                mx = height[i];
                count=1;
                cnt = height[i];
            }
        }
        
        mx = height[n-1],cnt=height[n-1],count=1;
        for(int i=n-2;i>=mxid;i--)
        {
            if(height[i]<mx)
            {
                cnt+= height[i];
                count++;
            }
            else
            {
                trappedWater+= (count*mx) - cnt;
                mx = height[i];
                count=1;
                cnt= height[i];
            }
        }
        
        return trappedWater;
        
    }
};