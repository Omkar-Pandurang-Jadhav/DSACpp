/*
Approach (Optimal O(n) Time, O(1) Extra Space):
------------------------------------------------
We want to create a deep copy of a linked list where each node has two pointers:
1. next  -> normal next node
2. random -> random node anywhere in the list (or NULL)

Steps:
1. First pass: Insert a copy node after each original node.
   Example:  A -> B -> C becomes A -> A' -> B -> B' -> C -> C'
   (A', B', C' are newly created copy nodes)

2. Second pass: Assign random pointers for the copied nodes.
   - If original node's random = R, then copy's random = R->next 
     (because the copy of R is placed right after R in the list).

3. Third pass: Separate the original list and the copied list.
   - Restore the original next pointers.
   - Extract the new list.

Why it works:
- By weaving copied nodes inside the original list, we avoid using extra hash maps.
- This ensures random pointers are set correctly without additional space.

Time Complexity: O(n)   (3 passes through the list)
Space Complexity: O(1)  (no extra data structures used, just pointers)
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* temp = head;

        // Step 1: Insert copy nodes after each original node
        while (temp != nullptr) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next; // move to next original node
        }

        // Step 2: Set random pointers for copy nodes
        temp = head;
        while (temp != nullptr) {
            if (temp->random != nullptr) {
                temp->next->random = temp->random->next;
            } else {
                temp->next->random = nullptr;
            }
            temp = temp->next->next; // move to next original node
        }

        // Step 3: Separate original list and copied list
        Node* dummy = new Node(-1); // dummy head for copied list
        Node* copyTail = dummy;
        temp = head;

        while (temp != nullptr) {
            copyTail->next = temp->next;     // attach copy node
            copyTail = copyTail->next;       // move copyTail
            temp->next = copyTail->next;     // restore original next
            temp = temp->next;               // move to next original node
        }

        return dummy->next; // head of deep copied list
    }
};
