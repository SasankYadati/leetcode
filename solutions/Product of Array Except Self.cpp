public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n,1);
        
        output[0] = 1;
        int rprod = 1;
        
        for(int i=1; i<n; i++)
        {
            output[i] = output[i-1]*nums[i-1];
        }
        
        for(int i=n-2; i>=0; i--)
        {
            rprod = rprod*nums[i+1];
            output[i] = output[i]*rprod;
        }
        
        return output;
    }
};
