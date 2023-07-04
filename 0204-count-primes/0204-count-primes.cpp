class Solution {
public:
    int countPrimes(int n) {
        
        int count=0;
        vector<bool> isprime(n,1);

        for(int i=2;i<n;i++)
        {
            if(isprime[i]) {
                count++;
                for(int j=2*i;j<n;j+= i)
                {
                    isprime[j]=0;
                }
            }
        }

        return count;
    }
};