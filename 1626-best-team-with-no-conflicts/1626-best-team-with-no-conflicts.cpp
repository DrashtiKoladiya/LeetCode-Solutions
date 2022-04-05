class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int n = scores.size(),mx=0;
        pair<int,int> v[n];
        int lis[n];
        memset(lis,0,sizeof(lis));
        
        for(int i=0;i<n;i++)
        {
            v[i].first = ages[i];
            v[i].second = scores[i];
        }
        
        sort(v,v+n);
        lis[0]=v[0].second;
        
        
        for(int i=1;i<n;i++)
        {
            lis[i]=v[i].second;
            for(int j=0;j<i;j++)
            {
                if(v[i].first==v[j].first || v[i].second >= v[j].second)
                {
                    lis[i] = max(lis[i],lis[j]+v[i].second);
                }
            }
            
            //cout<<lis[i]<<" ";
        }
        
        mx = *max_element(lis,lis+n);
        
        return mx;
        
    }
};