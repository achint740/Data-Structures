
//This Code only has the function used to solve this problem

bool has_cycle(SinglyLinkedListNode* head) {
   SinglyLinkedListNode *slow = head;
   SinglyLinkedListNode *fast = slow->next;
   while(1)
   {
       fast = fast->next;
       if(fast && fast->next)
       {
           slow = slow->next;
           fast = fast->next;
       }
       if(fast==NULL)
         return false;
     if(slow==fast)
        return true;
   }

}
