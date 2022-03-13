class Solution {
public:
    // differant ways to solve this problem
    // 1. slow-fast pointer technique
    // 2. using binary search with the concept of Pigeonhole principle
    // 3. normal hashing
    // 4. by making number at ith index negative 
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