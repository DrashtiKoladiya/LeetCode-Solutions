class Solution {
public:
    
    unordered_map<string, vector<int>> m;
    
    vector<int> diffWaysToCompute(string expression) {
        
        if(m.count(expression)!=0)
        {
            return m[expression];
        }
        
        
        vector<int> ans;
        int sz = expression.size();
        
        for(int i=0;i<sz;i++)
        {
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*')
            {
                vector<int> leftAns, rightAns;
                leftAns = diffWaysToCompute(expression.substr(0, i));
                rightAns = diffWaysToCompute(expression.substr(i+1, (sz-(i+1))));
                
                for(int j=0;j<leftAns.size();j++)
                {
                    for(int k=0;k<rightAns.size();k++)
                    {
                        if(expression[i]=='+')
                        {
                            ans.push_back(leftAns[j]+rightAns[k]);
                        }
                        else if(expression[i]=='-')
                        {
                            ans.push_back(leftAns[j]-rightAns[k]);
                        }
                        else
                        {
                            ans.push_back(leftAns[j]*rightAns[k]);
                        }
                    }
                }
                
            }
        }
        
        if(ans.size()==0) 
        {
            int num = 0;
            for(int i=0;i<sz;i++)
            {
                num*= 10;
                num+= (expression[i]-'0');
            }
            ans.push_back(num);
        }
        
        return ans;
        
    }
};