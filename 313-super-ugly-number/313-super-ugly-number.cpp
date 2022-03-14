class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int sz = primes.size();
        
        long long int ugly[n],idx[sz],nextNum[sz];
        memset(idx,0,sizeof(idx));
        ugly[0]=1;
        
        for(int i=0;i<sz;i++)
        {
            nextNum[i]=primes[i];
        }
        
        int i=1;
        while(--n)
        {
            long long int mn = nextNum[0];
            for(int i=1;i<sz;i++)
            {
                mn = min(mn,nextNum[i]);
            }
            
            ugly[i++]=mn;
            
            for(int i=0;i<sz;i++)
            {
                if(nextNum[i]==mn)
                {
                    idx[i]++;
                    nextNum[i] = primes[i]*ugly[idx[i]];
                }
            }
        }
        
        return ugly[i-1];
        
    }
};