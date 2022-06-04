class Solution {
public:
    vector<vector<int>> a = {{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{1,1},{-1,1},{1,-1},{0,0}};
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        
        unordered_map<int,unordered_map<int,int>> v;
        unordered_map<int,int> r,c,d,ud;
        vector<int> anss;
        
        
        for(auto it:lamps)
        {
            if(!v[it[0]][it[1]])
            {
                v[it[0]][it[1]]=1;
                r[it[0]]++;
                c[it[1]]++;
                d[it[0]-it[1]+(n-1)]++;
                ud[it[0]+it[1]]++;
            }
        }
        
        for(auto it:queries)
        {
            int ans = r[it[0]]!=0 | c[it[1]]!=0 | d[it[0]-it[1]+(n-1)]!=0 | ud[it[0]+it[1]]!=0;
            anss.push_back(ans);
            for(auto it1:a)
            {
                if(v[it[0]+it1[0]][it[1]+it1[1]])
                {
                    v[it[0]+it1[0]][it[1]+it1[1]]=0;
                    r[it[0]+it1[0]]--;
                    c[it[1]+it1[1]]--;
                    d[(it[0]+it1[0]) - (it[1]+it1[1]) + (n-1)]--;
                    ud[(it[0]+it1[0]) + (it[1]+it1[1])]--;
                }
            } 
        }
        
        return anss;
        
    }
};