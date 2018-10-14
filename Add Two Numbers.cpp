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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // need not worry about carry and unequal lengths of l1 and l2
        
        ListNode *res,*curr=NULL,*prev=NULL,*temp;
        int sum,carry=0;
        
        while(l1 && l2)
        {
            // find sum and carry
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            
            // create a new node
            temp = new ListNode(sum);
            
            // update prev and curr
            prev = curr;
            curr = temp;
            
            if(prev==NULL) // first node in the result ( always true in the 1st iteration )
            {
                res = curr;
            }
            else // not the first node
            { 
                prev->next = curr;
            }
            
            // move forward
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1)
        {
            sum = l1->val + carry;
            carry = sum/10;
            sum = sum%10;
            
            curr->next = new ListNode(sum);
            curr = curr->next;
            l1 = l1->next;
        }
        
        while(l2)
        {
            sum = l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            
            curr->next = new ListNode(sum);
            curr = curr->next;
            l2 = l2->next;
        }
        
        if(carry)
        {
            temp = new ListNode(carry);
            curr->next = temp;
        }
        
        return res;
    }
};
