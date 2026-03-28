/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    /*
    Approach:
    - Use slow and fast pointers to find middle.
    - Keep a 'prev' pointer to track node before 'slow'.
    - Move 'fast' by 2 steps, 'slow' by 1 step, and track 'prev' behind slow.
    - When loop ends:
        → If 'fast->next == NULL', list has odd number of nodes.
            - Delete 'slow' node using 'prev'.
        → Else, list has even number of nodes.
            - Delete node after 'slow'.
    - Adjust links accordingly and delete target node.

    Time Complexity: O(N)
    Space Complexity: O(1)
    */

    ListNode* deleteMiddle(ListNode* head) {
        // If list is empty or has one node, return NULL
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;

        // Move 'fast' by 2 and 'slow' by 1, track 'prev' behind slow
        while(fast->next != NULL && fast->next->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Case 1: Odd number of nodes (fast reaches last node)
        if(fast->next == NULL){
            prev->next = slow->next;  // Unlink middle node
            delete slow;              // Free memory
        }
        // Case 2: Even number of nodes (fast->next->next becomes NULL)
        else{
            ListNode* deleteNode = slow->next;
            slow->next = slow->next->next;  // Unlink next node
            delete deleteNode;              // Free memory
        }

        return head;
    }
};
