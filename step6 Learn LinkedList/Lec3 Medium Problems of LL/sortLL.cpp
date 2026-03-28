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

/**
 * Merge Sort on a Singly Linked List
 * 
 * Time Complexity: O(N log N)
 *      - Each split divides the list into halves: log N levels
 *      - Each merge step takes O(N) time to merge N nodes in total
 * 
 * Space Complexity:
 *      - O(log N) due to recursion stack depth (since list is split log N times)
 *      - No extra data structures, only pointers
 */

class Solution {
public:

    // Function to merge two sorted linked lists
    ListNode* mergerList(ListNode* leftNode, ListNode* rightNode){
        // Dummy node acts as a starting point for the merged list
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Traverse both lists and attach the smaller node each time
        while(leftNode != NULL && rightNode != NULL){
            if(leftNode->val > rightNode->val){
                temp->next = rightNode;
                rightNode = rightNode->next;
            }
            else{
                temp->next = leftNode;
                leftNode = leftNode->next;
            }
            temp = temp->next;
        }

        // If any nodes remain in either list, attach them
        if(leftNode) temp->next = leftNode;
        if(rightNode) temp->next = rightNode;

        // Return the head of the merged sorted list
        return dummy->next;
    }

    // Function to find the middle node of a linked list (slow-fast pointer)
    ListNode* middleNode(ListNode *head){
        ListNode* slow = head;
        ListNode* fast = head;

        // Move slow by 1 and fast by 2 nodes till fast reaches end
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow now points to the middle node
        return slow;
    }

    // Function to sort the linked list using Merge Sort
    ListNode* sortList(ListNode* head){
        // Base case: empty list or single node list is already sorted
        if(head == NULL || head->next == NULL) return head;

        // Find the middle node to split the list into two halves
        ListNode* middle = middleNode(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;

        // Disconnect the two halves
        middle->next = NULL;

        // Recursively sort both halves
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        // Merge the sorted halves and return the result
        return mergerList(leftHead, rightHead);
    }
};
