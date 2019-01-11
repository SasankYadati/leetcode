class Solution {
public:
    
    bool isAlphaNumeric(char ch) {
        return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9');
    }
    
    bool charMatch(char a, char b) {
        if(a==b)
            return true;
        else
        {
            if(a>='0' && a<='9' || b>='0' && b<='9') // if one of a and b are digits
                return false;
            else // both are alphabet
            {
                if(a>='a' && a<='z')
                {
                    return a-'a'==b-'A';
                }
                else
                {
                    return a-'A'==b-'a';
                }
            }
        }
    }
    
    bool isPalindrome(string s) {
        int n = s.length();
        if(n==0) return true;
        
        int i,j;
        i=0;
        j=n-1;
        while(i<=j)
        {
            while(i<=j && !isAlphaNumeric(s[i]))
            {
                i++;
            }
            while(i<=j && !isAlphaNumeric(s[j]))
            {
                j--;
            }
            
            if(i>j) return true;
            
            if(!charMatch(s[i],s[j]))
            {
                return false;   
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};
