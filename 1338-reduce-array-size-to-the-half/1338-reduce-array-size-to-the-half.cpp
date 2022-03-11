class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> cnt(1e5+1,0);
        
        for(int i=0;i<n;i++)
        {
            cnt[arr[i]]++;
        }
        
        sort(cnt.begin(),cnt.end(),greater<int>());
        int count=0,ans=0;
        for(int i=0;i<=1e5;i++)
        {
            count+= cnt[i];
            ans++;
            
            if(count >= (n/2))
            {
                break;
            }
        }
        
        return ans;
        
    }
};