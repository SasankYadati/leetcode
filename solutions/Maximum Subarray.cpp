class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // idea: dp
        int n = nums.size();
        int sum, max_sum;
        
        sum = nums[0];
        max_sum = sum;
        
        for(int i=1; i<n; i++){
            sum = max(nums[i], sum+nums[i]);
            max_sum = max(sum, max_sum);
        }
        
        return max_sum;
    }
};
