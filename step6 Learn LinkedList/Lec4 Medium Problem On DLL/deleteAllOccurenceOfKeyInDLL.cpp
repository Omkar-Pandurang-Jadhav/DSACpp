/*

You are given the head_ref of a doubly Linked List and a Key. Your task is to delete
 all occurrences of the given key if it is present and return the new DLL.

Example1:

Input: 
2<->2<->10<->8<->4<->2<->5<->2
2
Output: 
10<->8<->4<->5
Explanation: 
All Occurences of 2 have been deleted.
*/

/*
============================================================
DELETE ALL OCCURRENCES OF X IN DOUBLY LINKED LIST
============================================================

APPROACH:
- Check if list is empty
- Remove nodes from beginning if they match x
- Update head and set prev of new head to NULL
- Traverse remaining list:
    → If node matches x:
        - Connect prev node to next node
        - Update next node’s prev (if exists)
        - Delete current node
    → Otherwise move forward

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Each node is visited once

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

→ No extra space used

============================================================
*/

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        if(head_ref==NULL || *head_ref==NULL) return ;
        
        Node *temp=*head_ref;

        // delete matching nodes from head
        while(temp!=NULL && temp->data==x){
            Node *a=temp;
            temp=temp->next;
            delete(a);
        }

        *head_ref=temp;

        if(temp!=NULL) temp->prev=NULL;

        // delete remaining nodes
        while(temp!=NULL){
            if(temp->data==x){
                Node *a=temp;

                temp->prev->next=temp->next;

                if(temp->next!=NULL)
                    temp->next->prev=temp->prev;

                temp=temp->next;
                delete(a);
            }
            else temp=temp->next;
        }
    }
};