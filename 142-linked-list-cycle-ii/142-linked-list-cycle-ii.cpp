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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow,*fast;
        slow = head,fast = head;
        
        int f=0;
        // cheak wheather linkedlist contains cycle or nt
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast)
            {
                f=1;
                break;
            }
        }
        
        if(!f) return NULL;
        
        //find the starting point of the cycle
        slow=head;
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
        
    }
};