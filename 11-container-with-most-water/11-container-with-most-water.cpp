class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int i=0,j=n-1,mxarea=0;
        while(i<j)
        {
           int area = min(height[i],height[j])*(j-i);
           //cout<<i<<" "<<j<<" "<<area<<"\n";
           mxarea = max(mxarea,area);
            
           if(height[i]>height[j])
           {
               j--;
           }
           else
           {
               i++;
           }
        }
        
        return mxarea;
        
    }
};