class Solution {
public:
    static bool sortby(const pair<int,int> &p1,const pair<int,int> &p2)
    {
        if(p1.first < p2.first) return true;
        if(p1.first > p2.first) return false;
        return p1.second >= p2.second;
    }
    int minTaps(int n, vector<int>& ranges) {
        
        vector<pair<int,int>> v,a;
        for(int i=0;i<=n;i++)
        {
            v.push_back({max(0,i-ranges[i]),min(n,i+ranges[i])});
        }
        
        sort(v.begin(),v.end(),sortby);
        v.push_back({n,n+1});
        a.push_back(v[0]);
        
        
        for(int i=1;i<=(n+1);i++)
        {
            int sz = a.size();
            sz--;
            if(v[i].first >= a[sz].first && v[i].second <= a[sz].second)
            {
                //
            }
            else if(v[i].first > a[sz].second)
            {
                return -1;
            }
            else
            {
                if(sz<=0)
                {
                    a.push_back(v[i]);
                }
                else
                {
                    if(a[sz].second < v[i].second && v[i].first <= a[sz-1].second)
                    {
                        a.pop_back();
                    }
                    
                    a.push_back(v[i]);
                }
            }
        }
        
        return a.size()-1;
        
    }
};