class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        
        int total, sz = queries.size();
        vector<long long> poww(intLength, 0);
        poww[0] = 1;
        for(int i=1;i<intLength;i++)
        {
            long int ii = i;
            poww[i] = poww[i-1]*10;
        }
        total = 9*poww[((intLength+1)/2) - 1];
                
        vector<long long> ans1(sz, -1);
        for(int i=0;i<sz;i++)
        {
            if(queries[i] <= total)
            {
                int lp = 0, rp = intLength-1;
                long long int ans = 0, tmp = queries[i], id = ((intLength+1)/2) - 1;
                while(lp<=rp)
                {
                    long long int cnt = tmp/poww[id] + (tmp%poww[id] != 0);
                    tmp-= ((tmp/poww[id])*poww[id]);

                    if(lp!=0)
                    {
                        if(cnt==0) cnt=10;
                        cnt--;
                    }
                    
                    if(rp!=lp)
                    {
                        ans+= (cnt*poww[rp]);
                        ans+= (cnt*poww[lp]);
                    }
                    else
                    {
                        ans+= (cnt*poww[rp]);
                    }
                    
                    lp++, rp--;
                    id--;
                }
                
                ans1[i] = ans;
            }
        }
        
        return ans1;
        
    }
};