class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {

        vector<int> isprime(n+1,1);
        vector<vector<int>> ans;

        for(int i=2;i<=n;i++)
        {
            if(isprime[i])
            {
                for(int j=2*i;j<=n;j+= i)
                {
                    isprime[j]=0;
                }
            }
        }

        for(int i=2;i<=n/2;i++)
        {
            if(isprime[i] && (n-i)>=i && isprime[n-i])
            {
                ans.push_back({i,n-i});
            }
        }

        return ans;
        
    }
};