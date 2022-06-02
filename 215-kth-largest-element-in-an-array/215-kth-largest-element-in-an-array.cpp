class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> q;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            q.push(nums[i]); // each insert operation has O(logN) time complexity
        }
        
        int element = -1;
        
        while(k--)
        {
            element = q.top();
            q.pop(); // each delete operation has O(logN) time complexity
        }
        
        return element;
        
    }
};