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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val <= list2->val)
            {
                ListNode *next = list1->next;
                list1->next = NULL;
                curr->next = list1;
                list1 = next;
                
                //if(list1!=NULL) cout<<list1->val<<" l1\n";
            }
            else
            {
                ListNode *next = list2->next;
                list2->next = NULL;
                curr->next = list2;
                list2 = next;
                
                //if(list2!=NULL) cout<<list2->val<<" l2\n";
            }
            
            curr = curr->next;
        }
        
        if(list1!=NULL) curr->next = list1;
        if(list2!=NULL) curr->next = list2;
        
        return dummy->next;
        
    }
};