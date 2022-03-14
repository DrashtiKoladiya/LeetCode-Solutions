class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size(),j=0,f=0;
        int product = 1, mxproduct = -1e6,tmp;
        
        //if(n==1) return nums[0];
        
        for(int i=0;i<n;i++)
        {
            product*= nums[i];
            
            if(product>=0) mxproduct = max(mxproduct,product);
            else
            {
                if(!f)
                {
                    f=1;
                    tmp = product;
                    mxproduct = max(mxproduct,product);
                }
                else mxproduct = max(mxproduct,product/tmp);
            }
            
            if(product==0)
            {
                product=1;
                f=0;
            }
        }
        
        return mxproduct;
        
    }
};