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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res=NULL,*curr=NULL;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                if(res==NULL)
                {
                    res = l1;
                    curr = l1;
                }
                else
                {
                    curr->next = l1;
                    curr = curr->next;
                }
                l1 = l1->next;
            }
            else
            {
                if(res==NULL)
                {
                    res = l2;
                    curr = l2;
                }
                else
                {
                    curr->next = l2;
                    curr = curr->next;
                }
                l2 = l2->next;
            }
        }
        
        if(l1)
            curr->next = l1;
        if(l2)
            curr->next = l2;
        
        return res;
        
    }
};
