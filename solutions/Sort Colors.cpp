class Solution {
public:
    void sortColors(vector<int>& nums) {
        // counting sort
        int count[3] = {0,0,0};
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            count[nums[i]]++;
        }
        
        int i = 0;
        for(int k=0; k<3; k++){
            while(count[k]--){
                nums[i++] = k;
            }
        }   
    }
};
