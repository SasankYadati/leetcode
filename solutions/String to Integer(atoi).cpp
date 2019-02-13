class Solution {
public:
    int myAtoi(string str) {
        string num;
        unordered_set<int> digits = {'0','1','2','3','4','5','6','7','8','9'};
        bool is_negative = false;
        
        int n = str.length();
        if(n==0)
            return 0;
        
        int i=0;
        
        // skip spaces
        while(str[i] == ' '){
            i++;
        }
        
        // check if we point to '-'
        if(i<n){
            if(str[i]=='-'){
                is_negative = true;
                i++;
            }
            else if(str[i]=='+'){
                i++;
            }
        }
    
        // expect digits
        while(i<n && digits.find(str[i]) != digits.end())
        {
            num.push_back(str[i]);
            i++;
        }
        
        // remove zeros from the beginning.
        int x = 0;
        while(num.length() && num[x]=='0'){
            x++; // count no. of zeros
        }
        num.erase(0,x);
        
        // check if number of digits greater than 10, then return INT_MAX or INT_MIN
        if(num.length() > 10){
            if(is_negative)
                return INT_MIN;
            return INT_MAX;
        }
        
        long j = 1;
        int res = 0;
        for(int k=num.length()-1; k>=0; k--){
            // check overflow
            if(INT_MAX-res<j*(num[k]-'0')){
                if(is_negative)
                    return INT_MIN;
                return INT_MAX;
            }
            res += j*(num[k]-'0');
            j *= 10;
        }
        
        if(is_negative)
            return -res;
        
        return res;
    }
};
