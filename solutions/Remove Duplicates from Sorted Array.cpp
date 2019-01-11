class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==0) return 0;
        
        int i=0, j=1;
        
        while(i<n && j<n)
        {
            while(i<n && j<n && nums[i]==nums[j])
            {
                j++;
            }
            if(j<n)
            {
                nums[i+1] = nums[j];
                i++;
                j++;
            }
        }
        return i+1;
    }
};
