class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int prev = -1,mx=1,cnt=1;
        int n = arr.size();
        
        for(int i=1;i<n;i++)
        {
            if(prev==-1)
            {
                if(arr[i-1] > arr[i])
                {
                    prev = 0;
                    cnt++;
                }
                else if(arr[i-1] < arr[i])
                {
                    prev = 1;
                    cnt++;
                }
            }
            else if(prev==0)
            {
                if(arr[i-1] < arr[i])
                {
                    prev = 1;
                    cnt++;
                }
                else
                {
                    prev = -1;
                    i--;
                    cnt=1;
                }
            }
            else
            {
                if(arr[i-1] > arr[i])
                {
                    prev = 0;
                    cnt++;
                }
                else
                {
                    prev = -1;
                    i--;
                    cnt=1;
                }
            }
            
            //cout<<cnt<<" ";
            
            mx = max(mx,cnt);
        }
        
        return mx;
    }
};