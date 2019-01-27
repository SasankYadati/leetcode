class Solution {
public:
    bool isAnagram(string s, string t) {
        // only lowercase letters
        // use vector as a hashmap to store count
        int n = s.length();
        int m = t.length();
        
        if(n!=m) return false;
        vector<int> set(26,0);
        for(int i=0; i<n; i++) {
            set[s[i]-'a']++;
            set[t[i]-'a']--;
        }
        
        int i=0;
        while(i<26 && set[i]==0)
            i++;
        return i==26;
    }
};
