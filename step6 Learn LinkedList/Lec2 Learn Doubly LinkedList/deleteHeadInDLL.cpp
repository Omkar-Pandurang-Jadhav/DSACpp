/*
============================================================
DELETE HEAD NODE IN DOUBLY LINKED LIST
============================================================

APPROACH:
- Check if list is empty or has only one node → return NULL
- Store current head in temp
- Move head to next node
- Set new head's prev to NULL
- Delete old head node
- Return updated head

------------------------------------------------------------

TIME COMPLEXITY:
O(1)

→ Constant time, no traversal

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

→ No extra space used

============================================================
*/

Node *deleteHead(Node *head) {
    if(head==NULL || head->next==NULL) return NULL;
    
    Node *temp=head;
    head=head->next;
    head->prev=NULL;
    delete(temp);
    
    return head;
}