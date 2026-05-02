/*
============================================================
REVERSE DOUBLY LINKED LIST
============================================================

APPROACH:
- Traverse the list using a pointer (temp)
- For each node:
    → store next node
    → swap next and prev pointers
- Move to the original next node
- Update head to the current node during traversal
- Return new head at the end

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Traverse all nodes once

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

→ No extra space used

============================================================
*/

class Solution {
  public:
    Node *reverse(Node *head) {
        if(head==NULL || head->next==NULL) return head;

        Node *temp=head;
        Node *a;

        while(temp!=NULL){
            a=temp->next;
            temp->next=temp->prev;
            temp->prev=a;
            head=temp;
            temp=a;
        }

        return head;
    }
};