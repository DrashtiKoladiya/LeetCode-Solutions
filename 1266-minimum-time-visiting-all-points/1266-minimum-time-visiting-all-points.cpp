class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int ans = 0, n = points.size();
        
        for(int i=1;i<n;i++)
        {
            int xx = abs(points[i][0] - points[i-1][0]);
            int yy = abs(points[i][1] - points[i-1][1]);
            
            ans+= max(xx,yy);
        }
        
        return ans;
        
    }
};