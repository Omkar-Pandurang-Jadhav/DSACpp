/*  
    Problem: Sort a linked list of 0s, 1s and 2s without using extra data structures.

    Approach:
    - Create three dummy head nodes to build three separate lists:
        1. one for 0s
        2. one for 1s
        3. one for 2s
    - Traverse the original list once, attaching each node to the appropriate list.
    - After the traversal, link the 0s list to the 1s list (if exists), and 1s list to 2s list.
    - The final head will be the head of the 0s list.
    - Free the dummy nodes at the end to prevent memory leaks.

    Time Complexity:  O(N)
        - Single pass through the list for segregation (O(N))
        - Constant time operations for attaching nodes
        - Final connections done in O(1)

    Space Complexity: O(1)
        - No extra space proportional to input size
        - Only constant extra pointers used for dummy heads and iterators
*/

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* segregate(Node* head) {
        // Create dummy head nodes for lists of 0s, 1s, and 2s
        Node* head0 = new Node(-1);
        Node* head1 = new Node(-1);
        Node* head2 = new Node(-1);

        // Tail pointers for the three lists
        Node* temp0 = head0;
        Node* temp1 = head1;
        Node* temp2 = head2;

        // Iterator for the original list
        Node* temp = head;

        // Traverse the original list and attach nodes to respective lists
        while(temp != NULL){
            int val = temp->data;

            if(val == 0){
                temp0->next = temp;
                temp0 = temp0->next;
            }
            else if(val == 1){
                temp1->next = temp;
                temp1 = temp1->next;
            }
            else { // val == 2
                temp2->next = temp;
                temp2 = temp2->next;
            }

            // Move to next node
            temp = temp->next;
        }

        // Connect the three lists together
        // If 1s list exists, connect 0s list to 1s list, else to 2s list directly
        temp0->next = (head1->next) ? head1->next : head2->next;

        // Connect 1s list to 2s list
        temp1->next = head2->next;

        // Mark end of final list
        temp2->next = NULL;

        // New head is the start of 0s list
        head = head0->next;

        // Free dummy head nodes to avoid memory leaks
        delete head0;
        delete head1;
        delete head2;

        // Return the new sorted list head
        return head;
    }
};
