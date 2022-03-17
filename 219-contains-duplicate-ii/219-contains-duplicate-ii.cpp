class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n = nums.size();
        int cnt=0;
        map<int,int> m;
        
        for(int i=0;i<n;i++)
        {
            if(m.count(nums[i]))
            {
                int dis = abs(i-m[nums[i]]);
                if(dis<=k) return 1;
            }
            
            m[nums[i]]=i;
        }
        
        return 0;
        
    }
};