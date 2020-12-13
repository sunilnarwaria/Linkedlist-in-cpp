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
    ListNode* mergetwolist(ListNode* l1,ListNode* l2)
    {
         if(l1 == NULL || l2 == NULL) return l1 != NULL ? l1 : l2;
        
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        
        while(c1 != NULL && c2 != NULL)
        {
            if(c1->val <= c2->val)
            {
                prev->next = c1;
                c1 = c1->next;
            }
            else{
                prev->next = c2;
                c2 = c2->next;
            }
           prev = prev->next;     
        }
        prev->next = (c1 != NULL ? c1 :c2);
        return dummy->next;
    }
    ListNode* mklist(vector<ListNode*> lists,int si,int ei)
    {
       if(si == ei) return lists[si];
        int mid = (si+ei)/2;
        
        return mergetwolist(mklist(lists,si,mid),mklist(lists,mid+1,ei));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        if(n == 0) return NULL;
        
        return mklist(lists,0,n-1);
    }
};
