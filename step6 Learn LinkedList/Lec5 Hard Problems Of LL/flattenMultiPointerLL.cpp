/*
iven a linked list containing n head nodes where every node in the linked list contains two pointers:
(i) next points to the next node in the list.
(ii) bottom pointer to a sub-linked list where the current node is the head.
Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data.
Your task is to flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

Note:
1. ↓ represents the bottom pointer and -> represents the next pointer.
2. The flattened list will be printed using the bottom pointer instead of the next pointer.*/

/*
Node structure used in the program:

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

/*
Approach:
- Each node in the `next` pointer points to a new vertical sorted linked list using `bottom`.
- We need to flatten the entire structure into a single sorted list using only `bottom` pointers.
- We do this by merging two sorted bottom-linked lists at a time using `combineLL`.

Time Complexity: O(N), where N is the total number of nodes.
    - Each node is visited exactly once while merging.

Space Complexity: O(1) auxiliary
    - We only use a few pointers. No recursion or extra memory is used.
    - Output uses the original nodes rewired.

*/

class Solution {
public:
    // Merges two sorted bottom-linked lists
    Node* combineLL(Node* head1, Node* head2) {
        Node* temp = new Node(-1);   // Dummy node to build the result list
        Node* head = temp;

        Node* temp1 = head1;
        Node* temp2 = head2;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->data < temp2->data) {
                temp1->next = NULL;         // Clean up next pointer
                temp->bottom = temp1;       // Link to result list
                temp1 = temp1->bottom;
            } else {
                temp2->next = NULL;
                temp->bottom = temp2;
                temp2 = temp2->bottom;
            }
            temp = temp->bottom;
        }

        // Append remaining nodes from temp1
        while (temp1 != NULL) {
            temp1->next = NULL;
            temp->bottom = temp1;
            temp1 = temp1->bottom;
            temp = temp->bottom;
        }

        // Append remaining nodes from temp2
        while (temp2 != NULL) {
            temp2->next = NULL;
            temp->bottom = temp2;
            temp2 = temp2->bottom;
            temp = temp->bottom;
        }

        temp->bottom = NULL;  // End the list

        Node* result = head->bottom;
        delete head;          // Free the dummy node
        return result;
    }

    // Flattens the entire 2D list into a single bottom-linked sorted list
    Node* flatten(Node* root) {
        if (root == NULL || root->next == NULL) {
            return root;
        }

        Node* temp1 = root;
        Node* temp2 = root->next;
        Node* temp;

        while (temp2 != NULL) {
            temp = temp2->next;
            temp1 = combineLL(temp1, temp2);  // Merge two bottom lists
            temp2 = temp;
        }

        return temp1;
    }
};
