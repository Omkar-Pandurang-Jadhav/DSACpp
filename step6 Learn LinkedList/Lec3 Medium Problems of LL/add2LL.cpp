/*

Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of 
the linked list representing the sum of these two numbers.

For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5. Sum of these 
two numbers is represented by 2 -> 1 -> 5.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Examples:

Input: num1 = 4 - > 5, num2 = 3 -> 4 -> 5
Output:  3 -> 9 -> 0
 
Explanation: Given numbers are 45 and 345. There sum is 390.*/






/* 
Node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

/**
 * Problem:
 *  - Given two non-empty linked lists representing two non-negative integers.
 *  - The most significant digit comes first.
 *  - Add the two numbers and return the sum as a linked list in the same order.
 *
 * Approach:
 *  - Reverse both linked lists so we can easily add from least significant digit.
 *  - Add corresponding digits and manage carry.
 *  - Create new nodes for each digit of the result.
 *  - If a carry remains after processing both lists, create a final node.
 *  - Finally, reverse the result list to restore original order.
 *  - Handle edge case where result has a leading zero after reversal.
 *
 * Intuition:
 *  - Addition is performed from least significant to most significant digit.
 *  - Reversing both linked lists allows easy addition from head to tail.
 *  - After adding, reverse the result back to match original order.
 *
 * Time Complexity: O(N + M)
 *      - N = number of nodes in num1
 *      - M = number of nodes in num2
 *      - One reverse pass for each input: O(N + M)
 *      - One pass to add digits: O(max(N, M))
 *      - One final reverse: O(N + M)
 *      - Total: O(N + M)
 *
 * Space Complexity: O(N + M)
 *      - Space for new result linked list (max(N, M) + 1)
 *      - No extra space for data structures beyond that.
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
            Node* front = temp->next; // Save next node
            temp->next = prev;        // Reverse current link
            prev = temp;              // Move prev ahead
            temp = front;             // Move temp ahead
        }

        return prev;
    }

    // Main function to add two linked lists representing numbers
    Node* addTwoLists(Node* num1, Node* num2) {
        // Reverse both input lists to start addition from least significant digit
        num1 = reverseTheLL(num1);
        num2 = reverseTheLL(num2);

        int carry = 0;
        Node* temp1 = num1;
        Node* temp2 = num2;

        // Dummy node to simplify result list creation
        Node* dummy = new Node(-1);
        Node* temp = dummy;

        // Traverse both lists until both are exhausted
        while(temp1 != NULL || temp2 != NULL){
            int sum = carry;

            // Add current digit from num1 if exists
            if(temp1){
                sum += temp1->data;
                temp1 = temp1->next;
            }

            // Add current digit from num2 if exists
            if(temp2){
                sum += temp2->data;
                temp2 = temp2->next;
            }

            // Create new node for sum's unit digit
            Node* newNode = new Node(sum % 10);
            temp->next = newNode;

            // Update carry for next iteration
            carry = sum / 10;

            // Move temp to the new node
            temp = temp->next;
        }

        // If carry remains after full traversal, create final node
        if(carry != 0){
            Node* newNode = new Node(carry);
            newNode->next = NULL;
            temp->next = newNode;
        }

        // Reverse the result list to restore most-significant-digit-first order
        Node* result = reverseTheLL(dummy->next);

        // ✅ Fix: Remove leading zero if exists (corner case issue)
        if(result->data == 0 && result->next != NULL)
            result = result->next;

        return result;
    }
};
