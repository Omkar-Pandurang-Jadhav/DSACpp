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
    - Use two pointers: 'fast' and 'slow' both starting from head.
    - Move 'fast' pointer n steps ahead.
    - If 'fast' becomes NULL after n moves, it means we need to delete the head node.
    - Otherwise, move both 'fast' and 'slow' pointers one step at a time until 'fast' reaches the last node.
    - 'slow' will now be just before the target node to delete.
    - Adjust the links to delete the target node and free memory.
    
    Time Complexity: O(N)
    - We traverse the list at most twice (once for moving fast pointer n steps, then to the end)

    Space Complexity: O(1)
    - Only a constant number of pointers used.
    */

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;

        // Move 'fast' pointer n steps ahead
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        // If 'fast' is NULL, the node to delete is the head itself
        if(fast == NULL){
            head = head->next;
            delete slow;
            return head;
        }

        // Move both pointers until 'fast' reaches the last node
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        // 'slow->next' is the target node to delete
        ListNode *deleteNode = slow->next;
        slow->next = slow->next->next;  // Bypass the target node
        delete deleteNode;              // Free the memory of the deleted node

        return head;
    }
};
