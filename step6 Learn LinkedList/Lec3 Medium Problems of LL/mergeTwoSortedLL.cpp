/*
Question:
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted linked list. The merged list should
be created by splicing together the nodes of the two given lists.

Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

Approach:
1. Handle the cases where either of the linked lists is empty.
2. Create a dummy node to simplify the merging process.
3. Maintain two pointers to traverse both linked lists.
4. Compare the current nodes of both lists and attach the smaller node
   to the merged list.
5. Move the corresponding pointer forward and continue until one list
   is completely traversed.
6. Attach the remaining nodes of the non-empty list to the merged list.
7. Return the node next to the dummy node as the head of the merged list.

Time Complexity:
O(N + M)

where,
N = number of nodes in list1
M = number of nodes in list2

Space Complexity:
O(1)
since no extra data structure is used.
*/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // If the first list is empty, return the second list
        if (list1 == NULL) return list2;

        // If the second list is empty, return the first list
        if (list2 == NULL) return list1;

        // Dummy node to simplify insertion
        ListNode* head = new ListNode(-1);

        // Pointer used to build the merged list
        ListNode* h = head;

        // Pointers to traverse both linked lists
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        // Merge both lists while both contain nodes
        while (temp1 != NULL && temp2 != NULL) {

            // Attach the smaller node to the merged list
            if (temp1->val <= temp2->val) {
                h->next = temp1;
                temp1 = temp1->next;
            }
            else {
                h->next = temp2;
                temp2 = temp2->next;
            }

            // Move the merged list pointer forward
            h = h->next;
        }

        // Attach any remaining nodes from the first list
        while (temp1 != NULL) {
            h->next = temp1;
            temp1 = temp1->next;
            h = h->next;
        }

        // Attach any remaining nodes from the second list
        while (temp2 != NULL) {
            h->next = temp2;
            temp2 = temp2->next;
            h = h->next;
        }

        // Return the head of the merged linked list
        return head->next;
    }
};