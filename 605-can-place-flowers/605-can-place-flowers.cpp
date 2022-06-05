class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int sz = flowerbed.size();
        
        int cnt = 0;
        int tmp = 0;
        
        int i=0,j=sz-1;
        while(i<sz)
        {
            if(flowerbed[i]==0) 
            {
                i++;
                tmp++;
            }
            else break;
        }
        
        if(tmp==sz)
        {
            tmp++;
            return (tmp/2)>=n; 
        }
        
        cnt+= (tmp/2);
        tmp=0;
        
        while(j>i)
        {
            if(flowerbed[j]==0)
            {
                j--;
                tmp++;
            }
            else break;
        }
        cnt+= (tmp/2);
        tmp=0;
        
        for(int i1=i;i1<=j;i1++)
        {
            if(flowerbed[i1]==1)
            {
                cnt+= (max(0,(tmp-1)/2));
                tmp=0;
            }
            else
            {
                tmp++;
            }
        }
        
        cnt+= (max(0,(tmp-1)/2));
        
        //cout<<cnt<<" "<<n<<"\n";

        return cnt>=n;
    }
};