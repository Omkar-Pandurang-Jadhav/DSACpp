/*

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by 
continuously following the next pointer. Internally, pos is used to denote the index of the node that 
tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
*/




// User function Template for C++

/* 
struct Node
{
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
    Node* findFirstNode(Node* head) {
        // Declare a map to store addresses of visited nodes
        map<Node*, int> mpp;

        // Pointer to store result, initialized as NULL
        Node *a = NULL;

        // Edge case: if list is empty, no cycle possible
        if(head == NULL) return a;

        // Pointer to traverse the list
        Node *temp = head;

        // Counter to assign as value in map (not actually needed for detection)
        int i = 0;

        // Traverse the linked list
        while(temp != NULL){
            // If current node's address is already in map, cycle detected
            // Return the node where cycle starts
            if(mpp.find(temp) != mpp.end()) return temp;

            // Mark current node as visited by storing its address in map
            mpp[temp] = i;
            i++;

            // Move to next node
            temp = temp->next;
        }

        // If traversal ends (NULL reached), no cycle exists
        return a;
    }
};

/*
Approach:
- Use a map to store the address (pointer) of each visited node.
- While traversing the linked list:
    - If the current node's address is already in the map, a cycle exists.
    - Return that node immediately as it is the start of the cycle.
    - Otherwise, store the address in the map and move to the next node.
- If traversal reaches the end (NULL), no cycle exists; return NULL.

Time Complexity:  O(N)
- In the worst case, we traverse all N nodes once.

Space Complexity: O(N)
- In the worst case (no cycle), we store addresses of all N nodes in the map.

Note:
- This is a correct but space-inefficient approach.
- Optimal solution is Floyd's Tortoise and Hare (slow/fast pointer) algorithm 
  with O(1) space and O(N) time to both detect a cycle and find its starting node.
*/














