class Solution {
public:
    double myPow(double x, long int n) {
        if(x==0 || x==1)
            return x;
        if(n==0)
            return 1;
        
        if(n<0)
        {
            n = -n;
            x = 1/x;
        }
        
        if(n%2==0)
            return myPow(x*x, n/2);
        else
            return x*myPow(x*x, n/2);
    }
};
