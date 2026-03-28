/*
You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed 
by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Examples :

Input: LinkedList: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
*/


/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/**
 * Problem:
 *  - Given a number represented by a singly linked list where each node contains a single digit.
 *  - Add 1 to the number and return the new head of the list.
 *
 * Approach:
 *  - Reverse the linked list so that least significant digit comes to the front.
 *  - Traverse from head, add 1, and propagate any carry.
 *  - If carry remains after the last node, create a new node for it.
 *  - Finally, reverse the list again to restore the original order.
 *
 * Intuition:
 *  - Since adding starts from the least significant digit (last node),
 *    reversing simplifies addition from head to tail.
 *
 * Time Complexity: O(3N)
 *      - N is the number of nodes in the list.
 *      - One reverse pass: O(N)
 *      - One addition pass: O(N)
 *      - One final reverse pass: O(N)
 *      - Total: O(3N) → O(N)
 *
 * Space Complexity: O(1)
 *      - No extra space except a few pointers
 */

class Solution {
  public:
    // Function to reverse a singly linked list
    Node* reverseTheLL(Node* head){
        // Base case: empty or single node list is already reversed
        if(head == NULL || head->next == NULL){
            return head;
        }

        Node* temp = head;
        Node* prev = NULL;

        // Standard reverse loop
        while(temp != NULL){
            Node* front = temp->next; // Store next node
            temp->next = prev;        // Reverse current link
            prev = temp;              // Move prev ahead
            temp = front;             // Move temp ahead
        }

        // prev becomes new head
        return prev;
    }

    // Main function to add 1 to the number represented by linked list
    Node* addOne(Node* head) {
        // Reverse list to start adding from least significant digit
        head = reverseTheLL(head);

        Node* temp = head;
        int carry = 1; // Initialize carry as 1 since we're adding 1

        // Traverse list to add carry
        while(temp != NULL){
            temp->data += carry;

            if(temp->data < 10){
                // No carry generated, break early
                carry = 0;
                break;
            }
            else {
                // Carry generated, set current digit to 0 and carry forward 1
                temp->data = 0;
                carry = 1;
            }

            temp = temp->next;
        }

        // Reverse the list back to original order
        head = reverseTheLL(head);

        // If carry still exists after complete traversal, add new node at head
        if(carry){
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};






/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/**
 * Problem:
 *  - Given a number represented by a singly linked list where each node contains a single digit.
 *  - Add 1 to the number and return the new head of the list.
 *
 * Approach:
 *  - Use recursion to reach the last node (least significant digit).
 *  - Add 1 at the last node and propagate any carry back through recursion.
 *  - If carry remains after the head, create a new node for it.
 *
 * Intuition:
 *  - Since addition starts from the least significant digit (last node),
 *    recursion allows us to reach the end first, then add and propagate carry backward naturally via the call stack.
 *  - No need to reverse the list.
 *
 * Time Complexity: O(N)
 *      - N is the number of nodes in the list.
 *      - Each node is visited once.
 *
 * Space Complexity: O(N)
 *      - Call stack space for recursion is O(N)
 *      - No additional data structures used.
 */

class Solution {
  public:

    // Recursive helper function to add 1 to the number
    int helper(Node* head){
        // Base case: if current node is NULL, return carry 1
        if(head == NULL){
            return 1;
        }

        // Recursively add to the next node and get carry
        int carry = helper(head->next);

        // Add carry to current node
        head->data += carry;

        // If sum is less than 10, no further carry, return 0
        if(head->data < 10) return 0;

        // If sum is 10 or more, set current digit to 0 and carry forward 1
        head->data = 0;
        return 1;
    }

    // Main function to add 1 to the number represented by linked list
    Node* addOne(Node* head) {
        // Start recursion to add 1
        int carry = helper(head);

        // If carry exists after final recursion, create new node at head
        if(carry){
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};

