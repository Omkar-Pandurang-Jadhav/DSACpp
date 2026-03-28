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

/*
Approach:
- We are asked to rotate the linked list to the right by `k` positions.
- First, we calculate the length `n` of the list.
- Then we compute `k = k % n` because rotating `n` times leads to the same list.
- We find the `(n - k)`-th node which will become the new tail.
- The node after that becomes the new head.
- Then we connect the old tail to the original head and return the new head.

Time Complexity: O(N)
- One traversal to get the length.
- One traversal to find the (n-k)th node.
- One traversal to reach the end of the new list.

Space Complexity: O(1)
- No extra space used except for a few pointers.
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;  // Edge case: empty or single node list

        int n = 0;
        ListNode* temp = head;

        // Count the number of nodes in the list
        while(temp != NULL){
            temp = temp->next;
            n++;
        }

        temp = head;
        k = k % n;              // Effective rotation steps
        if(k == 0) return head; // No rotation needed

        int diff = n - k;
        ListNode* q;

        // Move temp to the (n-k)th node
        for(int i = 1; i <= diff; i++){
            q = temp;
            temp = temp->next;
        }

        q->next = NULL;         // Break the list at (n-k)th node
        ListNode* newHead = temp;

        // Traverse to the end of the new list
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = head;      // Connect end of list to the original head
        head = newHead;         // New head after rotation

        return head;
    }
};
