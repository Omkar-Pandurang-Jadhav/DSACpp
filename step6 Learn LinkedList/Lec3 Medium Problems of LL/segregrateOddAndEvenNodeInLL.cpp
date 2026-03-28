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
    - Use two pointers: temp1 to handle odd-positioned nodes, temp2 for even-positioned nodes.
    - temp3 stores the head of the even-positioned nodes to reconnect later.
    - Traverse the list using a counter 'cnt' to track positions:
        - If cnt is odd, link temp1 to the next odd-positioned node.
        - If cnt is even, link temp2 to the next even-positioned node.
    - After traversal:
        - Connect the last odd-positioned node's next to the head of even-positioned nodes (temp3).
        - Set the last even-positioned node's next to NULL to terminate the list.
    - Return the updated head.

    Time Complexity: O(N)
    - Each node is visited exactly once in the traversal.

    Space Complexity: O(1)
    - Only a constant number of pointers (temp1, temp2, temp3, cnt) are used.
    */

    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* temp3 = head->next;

        int cnt = 1;

        while(temp1->next != NULL && temp2->next != NULL){
            if(cnt % 2 == 1){
                temp1->next = temp1->next->next;
                temp1 = temp1->next;
            }
            else{
                temp2->next = temp2->next->next;
                temp2 = temp2->next;
            }
            cnt++;
        }

        temp1->next = temp3;
        temp2->next = NULL;

        return head;
    }
};
