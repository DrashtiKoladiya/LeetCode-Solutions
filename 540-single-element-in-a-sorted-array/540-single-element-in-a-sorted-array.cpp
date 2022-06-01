class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int l=0,r=n-1;
        
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            
            int leftc=0,rightc=0;
            
            leftc = mid;
            rightc = n - mid - 1;
            
            if((mid+1)<n && nums[mid]==nums[mid+1]) rightc--;
            
            if((mid-1)>=0 && nums[mid]==nums[mid-1]) leftc--;
            
            if(leftc%2)
            {
                r = mid-1;
            }
            else if(rightc%2)
            {
                l = mid+1;
            }
            else
            {
                return nums[mid];
            }
        }
        
        return -1;
        
    }
};