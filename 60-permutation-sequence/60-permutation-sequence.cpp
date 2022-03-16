class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> v(10),ans;
        for(int i=0;i<9;i++)
        {
            v[i]=i+1;
        }
        
        int tmp = 1,curr=1;
        
        while(curr<n)
        {
            tmp*= curr;
            curr++;
        }
        
        curr = n-1;
        
        while(k>0)
        {
            int id,id1;
            if(curr!=0)
            {
                id = k/tmp;
                if(k%tmp==0) id--;
            }
            else
            {
                id = 0;
            }
            
            id1=id;
            //cout<<id1<<" "<<tmp<<"\n";
            for(int i=0;i<9;i++)
            {
                if(v[i]!=0)
                {
                    id--;
                }
                
                if(id==-1)
                {
                    //cout<<v[i]<<" "<<id<<" "<<tmp<<" "<<k<<" "<<i<<"\n";
                    ans.push_back(v[i]);
                    v[i]=0;
                    break;
                }
            }
            
            if(curr==0) break;
            
            k-= (id1*tmp);
            tmp/= curr;
            curr--;
        }
        
        string s="";
        for(auto it:ans) s+= to_string(it);
        
        return s;
        
    }
};