class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num_bits = 0;
        while(n){
            if(n%2)
            {
                num_bits++;
            }
            n = n>>1;
        }
        return num_bits;
    }
};
