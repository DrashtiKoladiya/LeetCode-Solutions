class Solution {
public:
    // decimal to any base
    // step1: number divide by new base
    // step2: append remider at right to left fashion
    // step3: update number as number/(new base)
    // step4: repeat this step untill number becomes zero
    
    string convertToBase7(int num) {
        
        string ans = "";
        int f = 0;
        
        if(num==0) return "0";
        
        if(num<0)
        {
            f = 1;
            num = abs(num);
        }
        
        while(num)
        {
            int rem = num%7;
            num/= 7;
            
            ans+= ('0'+rem);
        }
        
        if(f) ans+= "-";
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};