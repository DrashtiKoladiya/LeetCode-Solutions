class Solution {
public:
    int kthElement(int k, vector<int>&nums1, vector<int>&nums2,int mn,int mx)
    {
        int l = mn, r = mx;
        
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            
            int leftc = upper_bound(nums1.begin(),nums1.end(),mid-1) - nums1.begin();
            leftc+= upper_bound(nums2.begin(),nums2.end(),mid-1) - nums2.begin();
            
            int rightc = (nums1.size() - (upper_bound(nums1.begin(),nums1.end(),mid) - nums1.begin()));
            rightc+= (nums2.size() - (upper_bound(nums2.begin(),nums2.end(),mid) - nums2.begin()));
            
            if(leftc < k)
            {
                if(rightc <= ((nums1.size()+nums2.size())-k))
                {
                    return mid;
                }
                else
                {
                    l = mid+1;
                }
            }
            else
            {
                r = mid - 1;
            }
        }
        
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int mn = INT_MAX, mx = INT_MIN;
        
        if(nums1.size()) mn=min(mn,nums1[0]),mx=max(mx,nums1[nums1.size()-1]);
        if(nums2.size()) mn=min(mn,nums2[0]),mx=max(mx,nums2[nums2.size()-1]);
        
        if((nums1.size()+nums2.size())%2)
        {
            return kthElement((nums1.size()+nums2.size()+1)/2,nums1,nums2,mn,mx);
        }
        else
        {
            int mid1 = kthElement((nums1.size()+nums2.size()+1)/2,nums1,nums2,mn,mx);
            int mid2 = kthElement((nums1.size()+nums2.size()+2)/2,nums1,nums2,mn,mx);
            
            return (mid1+mid2)/(2.0);
        }
        
        
        return -1;
        
    }
};