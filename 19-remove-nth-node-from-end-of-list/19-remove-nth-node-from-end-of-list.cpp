/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int remove(ListNode *head,int n)
    {
        if(head==NULL)
        {
            return -1;
        }
        
        int nodeidx = remove(head->next,n)+1;
        
        if(nodeidx==n)
        {
            head->next = head->next->next;
            //head->next->next = NULL;
        }
        
        return nodeidx;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;
        
        remove(head,n);
        return head->next;
    }
};