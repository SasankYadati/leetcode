/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isPalindrome(vector<TreeNode*>& level) {
    int n = level.size();
    for(int i=0; i<n; i++)
    {
        if(level[i])
            cout<<level[i]->val<<" ";
    }
    cout<<endl;
    for(int i=0; i<n/2; i++)
    {
        if(level[i] && level[n-i-1] && level[i]->val==level[n-i-1]->val)
            ;
        else if(level[i]==NULL && level[n-i-1]==NULL)
            ;
        else
            return false;
    }
    return true;
}
class Solution {
public:
    
    bool isSymmetric(TreeNode* root) {
        // idea: level order traversal, each level should be a palindrome
        // note: handle nulls as -1s
        
        if(root==NULL) return true;
        
        queue<TreeNode*> q;
        vector<TreeNode*> level;
        q.push(root);
        
        while(!q.empty())
        {
            
            while(!q.empty())
            {
                level.push_back(q.front());
                q.pop();
            }
            
            if(!isPalindrome(level))
                return false;    
            
            for(int i=0; i<level.size(); i++)
            {
                if(level[i])
                {
                    q.push(level[i]->left);
                    q.push(level[i]->right);    
                }
            }    
            level.clear();
        }
        
        return true;
    }
};
