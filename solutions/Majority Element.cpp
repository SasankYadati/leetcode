class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<short int,short int> counts;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(++counts[nums[i]] > (n>>1))
                return nums[i];
        }
        
        return -1; // never happens, majority element always exists
    }
};
