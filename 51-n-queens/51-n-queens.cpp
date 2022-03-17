class Solution {
public:
    vector<vector<string>> ans;
    void go(int src, int n,vector<string> ans1,vector<int> d,vector<int> ud,vector<int> &h,vector<int> &v)
    {
        if(src==n)
        {
            ans.push_back(ans1);
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
                ans1[src][i]='Q';
                go(src+1,n,ans1,d,ud,h,v);
                d[src-i+(n-1)]=0;
                ud[src+i]=0;
                h[src]=0;
                v[i]=0;
                ans1[src][i]='.'; 
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        ans.clear();
        vector<int> d(2*n-1,0),ud(2*n-1,0),h(n,0),v(n,0);
        vector<string> ans1(n,"");
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans1[i]+= ".";
            }
        }
        
        go(0,n,ans1,d,ud,h,v);
        
        return ans;
    }
};