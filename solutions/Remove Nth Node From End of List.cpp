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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // n is always valid
        ListNode *curr=head, *prev=NULL,*fast_curr=head;
        while(n--)
        {
            fast_curr = fast_curr->next;
        }
        
        while(fast_curr)
        {
            prev = curr;
            curr = curr->next;
            fast_curr = fast_curr->next;
        }
        
        if(curr==head)
        {
            prev = curr;
            curr = curr->next;
            free(prev);
            return curr;
        }
        else
        {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        
    }
};
