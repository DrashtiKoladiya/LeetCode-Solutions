class Solution {
public:
    static bool compareFirst(const vector<int> &a,const vector<int> &b)
    {
        if(a[1]!=b[1])
        {
            return a[1]<b[1];
        }
        
        return a[2]<b[2];
    }
    
    static bool compareLast(const vector<int> &a,const vector<int> &b)
    {
        if(a[2]!=b[2])
        {
            return a[2]<b[2];
        }
        
        return a[1]<b[1];
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int cnt=0;
        int n = trips.size(),i=0,j=0;
        
        vector<vector<int>> trips1 = trips;
        sort(trips.begin(),trips.end(),compareFirst);
        sort(trips1.begin(),trips1.end(),compareLast);
        
        while(i<n)
        {
            //cout<<trips[i][1]<<" "<<trips1[j][2]<<" ";
            if(trips[i][1]<trips1[j][2])
            {
                cnt+= trips[i][0];
                i++;
            }
            else
            {
                cnt-= trips1[j][0];
                j++;
            }
            
            //cout<<cnt<<" -- ";
            
            if(cnt>capacity) return 0;
        }
        
        return 1;
        
    }
};