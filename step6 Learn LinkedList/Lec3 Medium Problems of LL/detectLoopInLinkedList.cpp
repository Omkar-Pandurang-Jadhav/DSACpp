/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Declare a map to store addresses of visited nodes
        map<ListNode *, int> mpp;

        // Pointer to traverse the list
        ListNode *temp = head;

        // Counter to assign as value in map (not actually needed for detection)
        int i = 0;

        // Traverse the linked list
        while(temp != NULL){
            // If current node's address is already in map, a cycle is detected
            if(mpp.find(temp) != mpp.end()) return true;

            // Mark current node as visited by storing its address in map
            mpp[temp] = i;
            i++;

            // Move to next node
            temp = temp->next;
        }

        // If traversal ends (NULL reached), no cycle
        return false;
    }
};

/*
Approach:
- Use a map to store the address (pointer) of each visited node.
- While traversing the linked list:
    - If the current node's address is already in the map, a cycle exists.
    - Otherwise, store the address in the map and move to the next node.
- If traversal reaches the end (NULL), no cycle exists.

Time Complexity:  O(N)
- In the worst case, we traverse all N nodes once.

Space Complexity: O(N)
- In the worst case (no cycle), we store addresses of all N nodes in the map.

Note:
- This is a valid but space-inefficient approach.
- Optimal solution is Floyd's Tortoise and Hare (slow/fast pointer) algorithm with O(1) space.
*/

















/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Edge case: if the list is empty, no cycle possible
        if(head == NULL) return false;

        // Initialize two pointers: slow moves 1 step, fast moves 2 steps
        ListNode *slow = head;
        ListNode *fast = head;

        // Traverse the list
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;  // fast moves 2 steps
            slow = slow->next;        // slow moves 1 step

            // If slow and fast meet at any point -> cycle exists
            if(slow == fast) return true;
        }

        // If fast reaches end of list, no cycle
        return false;
    }
};

/*
Approach:
- Use Floyd's Cycle Detection Algorithm (Tortoise and Hare)
- Two pointers: slow moves 1 step at a time, fast moves 2 steps at a time
- If there’s a cycle, both pointers will meet inside the loop
- If there's no cycle, fast will reach NULL (end of list)

Time Complexity:  O(N)
- In worst case, both pointers traverse the list once

Space Complexity: O(1)
- No extra data structures used, only two pointers

This is the optimal approach for detecting a cycle in a singly linked list.
*/












/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Edge case: if list is empty or has one node only, no cycle possible
        if(head == NULL || head->next == NULL) return NULL;

        // Initialize two pointers: slow moves 1 step, fast moves 2 steps
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect if a cycle exists using Floyd's algorithm
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;         // move slow by 1
            fast = fast->next->next;   // move fast by 2

            // If slow and fast meet at any point -> cycle exists
            if(slow == fast){
                // Step 2: Reset slow pointer to head, keep fast at meeting point
                slow = head;

                // Move both one step at a time until they meet again
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }

                // Both pointers meet at the start of the cycle
                return slow;
            }
        }

        // If fast reaches the end of list, no cycle
        return NULL;
    }
};

/*
Approach:
- Use Floyd's Cycle Detection Algorithm (Tortoise and Hare)
- Step 1: Detect if a cycle exists by moving slow by 1 step and fast by 2 steps.
    - If they meet inside the list, a cycle exists.
- Step 2: To find the **starting point of the cycle**
    - Reset slow to head
    - Move both slow and fast one step at a time
    - Where they meet is the start of the cycle.

Intuition & Math:
Let:
- d = distance from head to start of cycle
- c = length of the cycle
- x = distance from start of cycle to meeting point inside the loop

When slow and fast meet:
- Slow covers distance = d + x
- Fast covers distance = d + x + n*c (because fast may have looped around the cycle n times)

Since fast moves twice as fast as slow:
→ 2*(d + x) = d + x + n*c  
→ 2d + 2x = d + x + n*c  
→ d + x = n*c  
→ d = n*c - x

Now, if you move one pointer to head and the other stays at meeting point:
- Move both one step at a time.
- One moves distance d to reach start of cycle.
- The other moves distance (n*c - x) to also reach start of cycle.
- They will meet at the start of the cycle after d steps.

Time Complexity:  O(N)
- Detecting the cycle takes at most N steps
- Finding start node takes at most N steps again

Space Complexity: O(1)
- Only two pointers used; no extra data structures

This is the most optimal and elegant solution to detect the starting node of a cycle in a singly linked list.
*/











