public:
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        if( l1 == NULL && l2 == NULL)
        return NULL;
        if( l1 == NULL)
        return l2;
        if( l2 == NULL)
        return l1;
        
        ListNode* a=l1;
        ListNode* b=l2;
        ListNode* p;
        
        if(a->val < b->val)
        {
        p = a;
        a = p->next;
        }
        else
        {
        p = b;
        b = p->next;
        }
        
        ListNode* head = p;
        while(a && b)
         {
          if(a->val < b->val)
          {
            p->next = a;
            p = a;
            a = p->next;
         }
          else
          {
            p->next = b;
            p = b;
            b = p->next;
          }
        }
        if(a == NULL)
          p->next = b;
        else if(b== NULL)
          p->next = a;
        return head;    
    }
    
    ListNode* sortList(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* t=head;
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast!=NULL && fast->next!=NULL){
            t=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        t->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(slow);
        
        return merge(left,right);
    }
    
    
};
