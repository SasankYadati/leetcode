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
    
    bool isValidBST_util(TreeNode* root, long int minimum, long int maximum)
    {
        if(root==NULL)
            return true;
        else
        {
            if(root->val>minimum && root->val<maximum)
                return isValidBST_util(root->left, minimum, root->val) && isValidBST_util(root->right, root->val, maximum);
            else
                return false;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST_util(root, LONG_MIN, LONG_MAX);
    }
};
