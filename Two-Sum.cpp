class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2,0);
        
        // idea : use a hashtable
        
        unordered_map<int,int> hmap; // (val, index)
        
        for(int i=0; i<nums.size(); i++)
        {
            if(hmap.find(target-nums[i])!=hmap.end()) // found a pair
            {
                res[0] = hmap[target-nums[i]];
                res[1] = i;
                return res;
            }
            hmap[nums[i]] = i;
        }
        return res;
    }
};
