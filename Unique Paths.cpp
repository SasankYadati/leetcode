class Solution {
public:
    int coeff(int m, int n) {
        long long int ans=1;
        
        int temp = m;
        if(n>m)
        {
            m = n;
            n = temp;
        }    
        
        for(int i=1; i<=n; i++)
        {
            ans *= (m+i);
        }
        for(int i=1; i<=n; i++)
        {
            ans /= i;
        }
        
        return ans;
    }
    int uniquePaths(int m, int n) {
        
        // need to go right m-1 times and down n-1 times in any valid path
        // how many such paths?
        // ans => (m+n-2)!/(m-1)!(n-1)!
        m = m-1;
        n = n-1;
        // => (m+n)!/m!n!
        // => (m+n)(m+n-1)...(m+1)/n!
        return coeff(m,n);
    }
};
