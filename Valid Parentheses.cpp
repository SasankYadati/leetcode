class Solution {
public:
    
    bool is_match(char a, char b)
    {
        if(a=='[' && b==']')
            return true;
        else if(a=='{' && b=='}')
            return true;
        else if(a=='(' && b==')')
            return true;
        return false;
    }
    
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        if(n%2) return false;
        
        int i=0;
        while(i<n)
        {
            // if open bracket, push.
            // if close bracket, pop and check.
            if(s[i]=='[' || s[i]=='{' || s[i]=='(')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()) return false;
                char ch = st.top();
                st.pop();
                if(is_match(ch,s[i]) == false) return false;
            }
            i++;
        }
        
        return st.empty();
    }
};
