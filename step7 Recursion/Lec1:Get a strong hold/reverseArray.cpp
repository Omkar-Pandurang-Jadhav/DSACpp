/*
QUESTION:
Given an array, reverse the array using recursion.

Example:
Input:  [1, 2, 3, 4]
Output: [4, 3, 2, 1]

-----------------------------------------------------

APPROACH (Recursion + Two Pointer):

Step 1: Use two-pointer idea
--------------------------------------
- Start from index i = 0
- Swap element at i with element at (n - i - 1)

--------------------------------------

Step 2: Recursive call
--------------------------------------
- Move i forward → i + 1
- Continue until middle of array

--------------------------------------

Step 3: Base condition
--------------------------------------
- Stop when i >= n/2
→ All elements are swapped

-----------------------------------------------------

WHY IT WORKS:
--------------------------------------
- Each recursion swaps one pair
- Total swaps = n/2
- Array gets reversed in-place

-----------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Each element is visited once (n/2 swaps)

-----------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ Due to recursion stack (depth = n/2)

-----------------------------------------------------

NOTE (Important Improvement):
--------------------------------------
- No need to check arr.size() == 1
- Base condition can be simplified to:
    if (i >= n/2) return;

-----------------------------------------------------
*/

class Solution {
public:
    void function(vector<int>& arr, int i) {

        // Base condition
        if (i >= arr.size() / 2) return;

        // Swap elements
        swap(arr[i], arr[arr.size() - i - 1]);

        // Recursive call
        function(arr, i + 1);
    }

    void reverseArray(vector<int> &arr) {
        function(arr, 0);
    }
};