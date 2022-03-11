class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<pair<int,int>> v;
        int n = arr.size();
        
        if(n==0) return arr;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i],i});
        }
        
        sort(v.begin(),v.end());
        arr[v[0].second]=1;
        for(int i=1;i<n;i++)
        {
            if(v[i].first==v[i-1].first)
            {
                arr[v[i].second]=arr[v[i-1].second];
            }
            else
            {
                arr[v[i].second]=arr[v[i-1].second]+1;
            }
        }
        
        return arr;
        
    }
};