class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int mx=INT_MIN,mn=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mn = min(mn,matrix[i][j]);
                mx = max(mx,matrix[i][j]);
            }
        }
        
        while(mn<=mx)
        {
            int mid = mn + (mx-mn)/2;
            int cnt1=0, cnt2=0;
            
            
            for(int i=0;i<n;i++)
            {
                cnt1+= upper_bound(matrix[i].begin(),matrix[i].end(),mid-1)-matrix[i].begin();
                cnt2+= (m - (upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin()));
            }
            
            if(cnt1<k)
            {
                if(cnt2<=(n*m-k)) return mid;
                else
                {
                    mn = mid+1;
                }
            }
            else
            {
                mx = mid-1;
            }
        }
        
        return -1;
        
    }
};