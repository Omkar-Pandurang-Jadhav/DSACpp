/*
QUESTION:
Given a string s, check whether it is a palindrome using recursion.

A palindrome reads the same forward and backward.

Example:
Input:  "madam"
Output: true

-----------------------------------------------------

APPROACH (Recursion + Two Pointer):

Step 1: Compare characters from both ends
--------------------------------------
- Compare s[i] with s[n - i - 1]

--------------------------------------

Step 2: Recursive call
--------------------------------------
- If characters match → move inward → i + 1
- Continue until middle of string

--------------------------------------

Step 3: Base condition
--------------------------------------
- If i >= n/2 → return true
→ All characters matched

- If any mismatch → return false immediately

-----------------------------------------------------

WHY IT WORKS:
--------------------------------------
- Each recursion checks one pair
- Stops early if mismatch found

-----------------------------------------------------

TIME COMPLEXITY:
O(n)

→ In worst case, we check all characters

-----------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ Due to recursion stack (depth = n/2)

-----------------------------------------------------

NOTE (Important Improvement):
--------------------------------------
- No need to check s.size() == 1
- Base condition can be simplified to:
    if (i >= n/2) return true;

-----------------------------------------------------
*/

class Solution {
public:
    bool isP(string &s, int i) {

        // Base condition
        if (i >= s.size() / 2) return true;

        // Check mismatch
        if (s[i] != s[s.size() - i - 1]) return false;

        // Recursive call
        return isP(s, i + 1);
    }

    bool isPalindrome(string& s) {
        return isP(s, 0);
    }
};