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
     ListNode* middleNode2(ListNode* head)
     {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
         ListNode* slow = head;
         ListNode* fast = head;
         while(fast->next != NULL && fast->next->next != NULL  )
         {
            slow = slow->next;
             fast = fast->next->next;
         }
         return slow;
     }
    
    ListNode* reverseList(ListNode* head)
    {
            if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* prev =NULL;
        ListNode* curr = head;
        while(curr != NULL)
        {
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
         return prev;
    
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode* middle = middleNode2(head);
        ListNode* nhead = middle->next;
        middle->next = NULL;
        
        
        nhead = reverseList(nhead);
        ListNode* c1 = head;
        ListNode* c2 = nhead;
        
        bool flag = true;
        while(c1 != NULL && c2 != NULL)
        {
           if(c1->val != c2->val){
              flag = false;
               break;
           }
            c1 = c1->next;
            c2 = c2->next;
        }
            
          nhead = reverseList(nhead);
         middle->next = nhead;
            return flag;
    }
};
