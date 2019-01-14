/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        
        ListNode *sp, *fp;
            
        sp = head;
        fp = head->next->next;
        
        while(fp && fp->next && sp!=fp)
        {
            sp = sp->next;
            fp = fp->next->next;
        }
        if(sp==fp) return true;
        return false;
        
    }
};
