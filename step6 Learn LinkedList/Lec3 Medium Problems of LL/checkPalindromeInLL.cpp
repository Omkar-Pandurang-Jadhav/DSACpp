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
    // Iterative reverse function to avoid recursive stack space
    ListNode* reverseLL(ListNode *head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        // Base case: empty list or single node is always a palindrome
        if(head==NULL || head->next==NULL) return true;

        // Use slow and fast pointers to find the middle of the list
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }

        // Reverse second half starting from slow->next
        ListNode *p = reverseLL(slow->next);

        // Compare first half and reversed second half
        ListNode *temp1=head;
        ListNode *temp2=p;
        while(temp2!=NULL){
            if(temp1->val!=temp2->val){
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }

        // Optional: restore original list structure by reversing again
        // slow->next = reverseLL(p);

        // If all values matched, it’s a palindrome
        return true;
    }
};















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
    ListNode* reverseLL(ListNode *head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode * front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {

        if(head==NULL || head->next==NULL) return true;
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *p;
        p=reverseLL(slow->next);
        ListNode *temp1=head;
        ListNode *temp2=p;
        while(temp2!=NULL){
            if(temp1->val!=temp2->val){
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
};