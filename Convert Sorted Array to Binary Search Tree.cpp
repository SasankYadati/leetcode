/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildBST(vector<int>& nums, int l, int r)
    {
        if(l<=r)
        {
            int m = (l+r)/2;
            TreeNode* temp = new TreeNode(nums[m]);
            temp->left = buildBST(nums, l, m-1);
            temp->right = buildBST(nums, m+1, r);
            return temp;
        }
        else
        {
            return NULL;
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = buildBST(nums, 0, nums.size()-1);
        return root;
    }
};
