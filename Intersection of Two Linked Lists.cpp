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
    int lengthList(ListNode* head) {
        ListNode* curr = head;
        int len = 0;
        while(curr)
        {
            curr = curr->next;
            len++;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA,lenB;
        
        lenA = lengthList(headA);
        lenB = lengthList(headB);
        
        int diff = max(lenA,lenB) - min(lenA,lenB);
        
        ListNode *currA = headA, *currB = headB;
        
        if(lenA>lenB)
        {
            while(diff)
            {
                currA = currA->next;
                diff--;
            }
        }
        else
        {
            while(diff)
            {
                currB = currB->next;
                diff--;
            }
        }
        while(currA!=NULL && currB!=NULL && currA!=currB)
        {
            currA = currA->next;
            currB = currB->next;
        }
        
        return currA;
    }
};
