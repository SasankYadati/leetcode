class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res; // each element is a triplet, no duplicate triplets
        // idea: presort
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=0,j,k;
        
        while(i<n){
            // i is the first element in the potential triplet
            // j and k are the other two
            j = i+1;
            k = n-1;
            
            while(j<k){
                // j and k should add upto -i for a triplet
                if(nums[j]+nums[k] == -nums[i])
                {
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[j]);
                    triplet.push_back(nums[k]);
                    res.push_back(triplet);
                    // increment j and decrement k while j+1 is same as j and k-1 is same as k
                    j++;
                    while(j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                    k--;
                    while(k > j && nums[k] == nums[k+1]){
                        k--;
                    }
                }
                else if(nums[j]+nums[k] > -nums[i])
                {
                    k--;
                    while(k > j && nums[k] == nums[k+1]){
                        k--;
                    }
                }
                else
                {
                    j++;
                    while(j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                }
            }
            i++;
            while(i<n && nums[i] == nums[i-1]){
                i++;
            }
        }
        return res;
    }
};
