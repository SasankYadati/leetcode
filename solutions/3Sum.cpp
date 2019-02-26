class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res; // each element is a triplet, no duplicate triplets
        // idea: presort
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i,j,k;
        
        vector<int> triplet;
        int sum_jk;
        
        for(int i=0; i<n;){
            // i is the first element in the potential triplet
            // j and k are the other two
            j = i+1;
            k = n-1;
            
            while(j<k){
                // j and k should add upto -i for a triplet
                sum_jk = nums[j]+nums[k];
                if(sum_jk == -nums[i])
                {
                    triplet = {nums[i], nums[j], nums[k]};
                    // triplet.push_back(nums[i]);
                    // triplet.push_back(nums[j]);
                    // triplet.push_back(nums[k]);
                    res.push_back(triplet);
                    triplet.clear();
                    // increment j and decrement k while j+1 is same as j and k-1 is same as k
                    
                    do{
                        j++;
                    }while(j < k && nums[j] == nums[j-1]);
                    
                    do{
                        k--;
                    }while(k > j && nums[k] == nums[k+1]);
                }
                else if(sum_jk > -nums[i])
                {
                    do{
                        k--;
                    }while(k > j && nums[k] == nums[k+1]);
                }
                else
                {
                    do{
                        j++;
                    }while(j < k && nums[j] == nums[j-1]);
                }
            }
            do{
                i++;
            }while(i < n-2 && nums[i] == nums[i-1]);
        }
        return res;
    }
};
