class Solution {
public:
    string lcpTwoStrings(string a, string b) {
        int n = min(a.size(),b.size());
        string res = "";
        int i = 0;
        while(i<n && a[i]==b[i])
        {
            res.push_back(a[i]);
            i++;
        }
        
        return res;
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        if(n==0) return "";
        string res = strs[0];
        for(int i=1; i<n; i++)
        {
            res = lcpTwoStrings(res, strs[i]);
            if(res=="")
                return res;
        }
        return res;
    }
};
