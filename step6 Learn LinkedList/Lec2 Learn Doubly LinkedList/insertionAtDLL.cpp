/*
Given the head of a doubly-linked list, a position p, and an integer x. Add a new 
node with value x at the position just after pth node in the doubly linked list and
 return the head of the updated list.

Note: The position is 0-based indexed.*/

/*
============================================================
INSERT NODE AT GIVEN POSITION IN DOUBLY LINKED LIST
============================================================

PROBLEM:
- Given head of DLL
- Insert a node with value x at position p

============================================================


------------------------------------------------------------
1️⃣ YOUR APPROACH
------------------------------------------------------------

APPROACH:
- Create new node
- Traverse till position p
- Adjust pointers:
    → temp->next = newNode
    → newNode->prev = temp
    → connect with next node if exists

------------------------------------------------------------

TIME COMPLEXITY:
O(p)

→ Traverse from head to position p

Worst case:
O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

→ Only one new node created

------------------------------------------------------------

NOTE:
- Assumes position p is valid
- Inserts AFTER node at index p
- Does not handle insertion at head (p = 0 case ❗)

------------------------------------------------------------
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        Node *newNode = new Node(x);
        Node *temp = head;
        int cnt = 0;

        while(cnt != p){
            temp = temp->next;
            cnt += 1;
        }

        Node *tempNext = temp->next;

        temp->next = newNode;
        newNode->prev = temp;

        if(tempNext != NULL){
            newNode->next = tempNext;
            tempNext->prev = newNode;
        }
        else newNode->next = NULL;

        return head;
    }
};



/*
============================================================
CAN THIS BE OPTIMIZED?
============================================================

👉 Time Complexity:
❌ Cannot improve (must traverse to position)

👉 Space Complexity:
✅ Already optimal (O(1))

------------------------------------------------------------

============================================================
⚠️ EDGE CASES (IMPORTANT)
============================================================

1. p == 0 (insert at head) ❌ NOT handled
2. head == NULL ❌ NOT handled
3. p > length ❌ undefined behavior

------------------------------------------------------------

============================================================
BETTER SAFE VERSION (handles edge cases)
============================================================
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {

        Node *newNode = new Node(x);

        // insert at head
        if(p == 0){
            if(head != NULL){
                newNode->next = head;
                head->prev = newNode;
            }
            return newNode;
        }

        Node *temp = head;
        int cnt = 0;

        while(temp != NULL && cnt < p-1){
            temp = temp->next;
            cnt++;
        }

        // invalid position
        if(temp == NULL) return head;

        Node *tempNext = temp->next;

        temp->next = newNode;
        newNode->prev = temp;

        if(tempNext != NULL){
            newNode->next = tempNext;
            tempNext->prev = newNode;
        }

        return head;
    }
};



/*
============================================================
FINAL TAKEAWAY
============================================================

👉 Your code:
- ✅ Correct pointer logic
- ❌ Missing edge cases

👉 Optimal solution:
- Same time O(n)
- Same space O(1)
- Just safer handling

============================================================
*/