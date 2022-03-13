class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size(),slow,fast,prev;
        slow = nums[0], fast = nums[0];
        
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        //cout<<slow<<" "<<fast<<"\n";
        
        slow = nums[0];
        while(slow!=fast)
        {
            prev = slow;
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
        
    }
};