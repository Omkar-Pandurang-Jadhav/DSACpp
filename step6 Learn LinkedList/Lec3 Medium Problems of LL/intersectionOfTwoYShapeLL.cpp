// Linked list Node definition
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

/**
 * Problem: Find the intersection point of two linked lists.
 * 
 * Approach:
 * - Use a hash map (unordered_map or map) to store visited nodes of the first linked list.
 * - Traverse the second linked list and check for the first node that appears in the map.
 * - Return that node as the intersection point.
 * 
 * Time Complexity: O(N + M)
 *      - N: number of nodes in first list
 *      - M: number of nodes in second list
 * 
 * Space Complexity: O(N)
 *      - Storing addresses of N nodes from the first list in a map
 */

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        // Map to store addresses of nodes from first linked list
        map<Node*, int> mpp;

        // Pointer to traverse first list
        Node* temp1 = head1;

        // Insert all nodes of first list into the map
        while(temp1 != NULL){
            mpp[temp1] = 1;
            temp1 = temp1->next;
        }

        // Pointer to traverse second list
        Node* temp2 = head2;

        // Traverse second list and check for first common node in map
        while(temp2 != NULL){
            if(mpp.find(temp2) != mpp.end()){
                // Intersection point found
                return temp2;
            }
            temp2 = temp2->next;
        }

        // If no intersection point found
        return NULL;
    }
};










/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Problem: Find the intersection point of two singly linked lists.
 * 
 * Approach:
 * - Calculate the lengths of both linked lists.
 * - Move the pointer of the longer list ahead by the difference in lengths.
 * - Then move both pointers together one by one until they meet — that meeting node is the intersection.
 * 
 * Time Complexity: O(min(N,M)+2*max(N,M))
 *      - N: number of nodes in list A
 *      - M: number of nodes in list B
 *      - One pass to compute lengths, one pass to align pointers, and one pass to find intersection
 * 
 * Space Complexity: O(1)
 *      - No extra space used, just pointers
 */

class Solution {
public:
    // Function to calculate the length of a linked list
    int LengthOfLL(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;

        // Traverse through the list and count nodes
        while(temp != NULL){
            temp = temp->next;
            cnt++;
        }

        return cnt;
    }
   
    // Function to find intersection point given the longer, shorter list and their length difference
    ListNode* intersectionPoint(ListNode* large, ListNode* small, int d){
        ListNode* l = large;
        ListNode* s = small;

        // Move the pointer of the longer list by 'd' nodes
        while(l != NULL){
            if(d == 0) break;
            l = l->next;
            d--;
        }

        // Move both pointers together till they meet
        while(l != s){
            l = l->next;
            s = s->next;
        }

        // Either intersection point or NULL if no intersection
        return s;
    }

    // Main function to get the intersection node of two linked lists
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        // Get lengths of both lists
        int cntA = LengthOfLL(headA);
        int cntB = LengthOfLL(headB);

        ListNode* ans;

        // Call intersectionPoint by passing the longer and shorter list accordingly
        if(cntA > cntB){
            ans = intersectionPoint(headA, headB, cntA - cntB);
        }
        else {
            ans = intersectionPoint(headB, headA, cntB - cntA);
        }

        return ans;
    }
};













/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Problem:
 *  - Find the intersection point of two singly linked lists.
 *  - If no intersection, return NULL.
 *
 * Approach:
 *  - Use two pointers: temp1 starting at headA, temp2 starting at headB.
 *  - Traverse both lists one step at a time.
 *  - When a pointer reaches the end, redirect it to the head of the other list.
 *  - When both pointers are equal (either at intersection or both NULL), return that node.
 *
 * Intuition:
 *  - If two linked lists intersect, the portions after the intersection are the same.
 *  - By swapping heads when a pointer reaches the end, both pointers traverse equal total lengths:
 *      (length of A + length of B)
 *  - On the second pass, they align at the intersection point (if exists), else both become NULL.
 *  - This way, no need to compute lengths or use extra space.
 *
 * Time Complexity: O(N + M)
 *      - N: number of nodes in list A
 *      - M: number of nodes in list B
 *
 * Space Complexity: O(1)
 *      - Constant extra space — only two pointers used
 */

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // Initialize two pointers at the heads of both lists
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        // Traverse both lists until pointers meet (or both become NULL)
        while(temp1 != temp2) {
            // Move both pointers one step forward
            temp1 = temp1->next;
            temp2 = temp2->next;

            // If they meet after moving, return intersection node
            if(temp1 == temp2) return temp1;

            // If temp1 reaches end of its list, redirect to head of list B
            if(temp1 == NULL) temp1 = headB;

            // If temp2 reaches end of its list, redirect to head of list A
            if(temp2 == NULL) temp2 = headA;
        }

        // Either intersection node or NULL (if no intersection exists)
        return temp1;
    }
};
