class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string s)
    {
        int n = s.size();
        int l=0,r=n-1;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return 0;
            }
            l++;
            r--;
        }
        
        return 1;
    }
    void backtrack(string &s,int src,vector<string> ans1)
    {
        if(src==s.size())
        {
            ans.push_back(ans1);
        }
        
        for(int i=src;i<s.size();i++)
        {
            string tmp = s.substr(src,i-src+1);
            if(isPalindrome(tmp))
            {
                ans1.push_back(tmp);
                backtrack(s,i+1,ans1);
                ans1.pop_back();
            }
        }
        
        
    }
    vector<vector<string>> partition(string s) {
        
        vector<string> ans1;
        ans.clear();
        
        backtrack(s,0,ans1);
        return ans;
        
        
    }
};