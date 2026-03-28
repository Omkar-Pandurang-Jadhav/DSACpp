/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Edge case: if list is empty, no loop possible
        if(head == NULL) return 0;

        // Initialize two pointers: slow moves 1 step, fast moves 2 steps
        Node *slow = head;
        Node *fast = head;

        // Traverse the list using Floyd's Cycle Detection algorithm
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;  // fast moves 2 steps
            slow = slow->next;        // slow moves 1 step

            // If slow and fast meet at any point -> cycle exists
            if(slow == fast){
                // Initialize counter to 1 for current meeting node
                int cnt = 1;

                // Move fast one step ahead
                fast = fast->next;

                // Traverse the cycle until fast meets slow again
                while(fast != slow){
                    fast = fast->next;
                    cnt++;
                }

                // Return length of the cycle
                return cnt;
            }
        }

        // If fast reaches end of list, no loop
        return 0;
    }
};

/*
Approach:
- Use Floyd's Cycle Detection Algorithm (Tortoise and Hare)
- Detect if a cycle exists by moving slow by 1 and fast by 2 steps
- If they meet, a cycle is confirmed
- Then, to count the number of nodes in the loop:
    - Move one pointer (fast) one step at a time
    - Increment a counter until it again meets the other pointer (slow)
- Return the count as the loop length

Time Complexity:  O(N)
- Detecting the cycle takes at most N steps
- Counting the cycle length takes at most N steps

Space Complexity: O(1)
- Only two pointers and one counter variable used

This is an efficient and correct method to detect a loop and count its length in a singly linked list.
*/
