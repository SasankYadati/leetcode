class Solution {
public:
    int countPrimes(int n) {
        vector<int> is_prime(n,1);
        int num_primes=0;
        for(long int i=2; i<n; i++)
        {
            if(is_prime[i])
            {
                num_primes++;
                for(long int j=i*i; j<n; j+=i)
                {
                    is_prime[j] = 0;
                }
            }
        }
        return num_primes;
    }
};
