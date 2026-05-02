/*
Given a doubly linked list of n nodes sorted by values, remove duplicate nodes 
present in the linked list.

Examples:

Input: n = 6, Linked List: 1<->1<->1<->2<->3<->4
Output: 1<->2<->3<->4
Explanation:
Only the first occurance of node with value 1 is 
retained, rest nodes with value = 1 are deleted.*/

/*
============================================================
REMOVE DUPLICATES FROM DOUBLY LINKED LIST (YOUR APPROACH)
============================================================

APPROACH:
- Traverse from head
- First remove duplicates at beginning (if multiple same values)
- Update head after removing initial duplicates
- Traverse remaining list:
    → If current node equals next node:
        - Remove current node by fixing prev and next pointers
        - Delete node
    → Else move forward

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
    Node* removeDuplicates(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        
        Node *temp=head;
        
        while(temp->data==temp->next->data){
            Node *a=temp;
            temp=temp->next;
            delete(a);
        }
        head=temp;
        while(temp->next!=NULL){
            if(temp->data==temp->next->data){
                Node *a=temp;
                temp->prev->next=temp->next;
                if(temp->next!=NULL) temp->next->prev=temp->prev;
                temp=temp->next;
                delete(a);
            }
            else temp=temp->next;
        }
        return head;
    }
};