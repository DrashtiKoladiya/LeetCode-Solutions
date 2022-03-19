class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        int n = nums.size();
        multiset<long long int> s;
        
        for(int i=0;i<n;i++)
        {
            //cout<<"o hello\n";
            if(s.size()!=0) 
            {
            
                auto it1 = s.upper_bound(nums[i]);
                auto it2 = it1;
                if(it1!=s.begin()) it2--;
            
                //cout<<*it1<<" "<<*it2<<" "<<nums[i]<<" "<<i<<"\n";
            
                if((it1!=s.end() && (abs((long)nums[i]-*it1))<=t) || abs(((long)nums[i]-*it2))<=t)
                {
                    return 1;
                }
            }
            
            s.insert(nums[i]);
            
            if((i-k)>=0)
            {
                s.erase(s.find(nums[i-k]));
            }
        }
        
        return 0;
        
    }
};