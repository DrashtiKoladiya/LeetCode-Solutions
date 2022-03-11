class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        
        priority_queue<int> q1; // max element of the first priority_queue
        priority_queue<int,vector<int>,greater<int>> q2; // min element of the second priority_queue
        
        int n = nums.size(),cnt1=0,cnt2=0,last=-1;
        vector<double> ans;
        map<int,int> tmp;
        
        if(k==1)
        {
            for(int i=0;i<n;i++)
            {
                ans.push_back(nums[i]);
            }
            
            return ans;
        }
        
        int i = 0,l=0,r=k;
        
        // Initialize the heaps
        while (i < k)  { q1.push(nums[i++]); }
        for (int count = k/2; count > 0; --count) {
            q2.push(q1.top()); q1.pop();
        }

        while(r<=n)
        {
            if(k%2)
            {
                ans.push_back(q1.top());
            }
            else
            {
                long long int tmp = (long)q1.top() + (long)q2.top();
                ans.push_back(tmp/(2*1.0));
            }
            
            if(r==n) break;
            
            int balance=0;
            
            // removing the element that is out of window
            if(nums[l] <= q1.top()) 
            {
                balance--;
                if(q1.top()==nums[l]) q1.pop();
                else tmp[nums[l]]++;
            }
            else
            {
                balance++;
                if(q2.top()==nums[l]) q2.pop();
                else tmp[nums[l]]++;
            }
            
            // adding new element of the window
            if(nums[r] <= q1.top())
            {
                balance++;
                q1.push(nums[r]);
            }
            else
            {
                balance--;
                q2.push(nums[r]);
            }
            
            // rebalancing the size of queues
            if(balance < 0)
            {
                q1.push(q2.top());
                q2.pop();
            }
            else if(balance > 0)
            {
                q2.push(q1.top());
                q1.pop();
            }
            
            // removing out of window elements
            while(!q1.empty() && tmp[q1.top()]>0)
            {
                tmp[q1.top()]--;
                q1.pop();
            }
            while(!q2.empty() && tmp[q2.top()]>0)
            {
                tmp[q2.top()]--;
                q2.pop();
            }
            
            
            l++;
            r++;
        }
        
        return ans;
    }
};