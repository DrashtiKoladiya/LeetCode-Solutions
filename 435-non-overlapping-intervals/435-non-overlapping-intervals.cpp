class Solution {
public:
    // x1 <= y2 && y1 <= x2

    bool static compare(const vector<int> &a1,const vector<int> &a2)
    {
        if(a1[1]!=a2[1])
        {
            return a1[1]<a2[1];
        }
        
        return a1[0]>a2[0];
    }
    
    int cheak(int x1,int x2,int y1,int y2)
    {
        return (x1 < y2 && y1 < x2);
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        
        sort(a.begin(),a.end(),compare);
        int l=a[0][0], r=a[0][1],cnt=0;
        
        for(int i=1;i<a.size();i++)
        {
            if(!cheak(l,r,a[i][0],a[i][1]))
            {
                l = a[i][0], r = a[i][1];
            }
            else 
            {
                //cout<<l<<" "<<r<<" "<<a[i][0]<<" "<<a[i][1]<<"\n";
                cnt++;
            }
        }
        
        return cnt;   
        
    }
};

