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
- The problem is to reverse nodes of a linked list in groups of size k.
- We recursively reverse k nodes using a helper function `reverseLL`.
- To identify the k-th node from a given node, we use the helper `kthNode`.
- In the main function `reverseKGroup`, we iterate through the list group by group.
  - For each group:
    - Find the k-th node.
    - Temporarily disconnect it from the next part of the list.
    - Reverse the group.
    - Connect the previous part with the newly reversed head.
    - Move forward by k steps and repeat.
- If the remaining nodes are less than k, we leave them as-is.

Time Complexity: O(N)
- Each node is visited once during traversal.
- The reverse operation for k nodes is O(k), done N/k times => O(N).

Space Complexity: O(k) (Recursive Stack)
- The reverseLL function uses recursion which goes up to depth k.
- So auxiliary stack space is O(k), no additional data structures used.

*/

class Solution {
public:
    // Helper function to reverse a linked list
    ListNode *reverseLL(ListNode * head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        // Recursively reverse the rest
        ListNode* newhead=reverseLL(head->next);
        ListNode* front=head->next;
        front->next=head;     // Reverse the link
        head->next=NULL;      // Break the original link

        return newhead;
    }

    // Helper function to get the k-th node from current node
    ListNode* kthNode(ListNode* head,int k){
        int i=1;
        ListNode *temp=head;
        while(i!=k && temp!=NULL){
            temp=temp->next;
            i++;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* kth;
        ListNode* prev = NULL;
        ListNode* nextNode;

        while(temp != NULL){
            kth = kthNode(temp, k);   // Find the k-th node from current group
            if(kth == NULL){
                if(prev) prev->next = temp;  // Attach the remaining nodes if < k
                break;
            }

            nextNode = kth->next;    // Store next group's head
            kth->next = NULL;        // Temporarily disconnect current k-group

            reverseLL(temp);         // Reverse current group

            if(temp == head){
                head = kth;          // Update head on first reversal
            }
            else {
                prev->next = kth;    // Link previous group's tail to new head
            }

            prev = temp;             // Move prev to current group's tail
            temp = nextNode;         // Move to next group
        }

        return head;
    }
};
