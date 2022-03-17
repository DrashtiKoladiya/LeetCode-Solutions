class Solution {
public:
    int n1=0;
    void go(int src, int n,vector<int> d,vector<int> ud,vector<int> &h,vector<int> &v)
    {
        if(src==n)
        {
            n1++;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(d[src-i+(n-1)]==0 && ud[src+i]==0 && h[src]==0 && v[i]==0)
            {
                d[src-i+(n-1)]=1;
                ud[src+i]=1;
                h[src]=1;
                v[i]=1;
                go(src+1,n,d,ud,h,v);
                d[src-i+(n-1)]=0;
                ud[src+i]=0;
                h[src]=0;
                v[i]=0;
            }
        }
    }
    
    int totalNQueens(int n) {
        
        n1=0;
        vector<int> d(2*n-1,0),ud(2*n-1,0),h(n,0),v(n,0);
        
        go(0,n,d,ud,h,v);
        
        return n1;
    }
};