/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.

 */


class Solution {
public:
    bool isValid(string s) {
        // Approach:
        // 1. Use a stack to store opening brackets '(' '[' '{'.
        // 2. Traverse the string:
        //    - If an opening bracket, push onto the stack.
        //    - If a closing bracket:
        //        a) If stack is empty, return false.
        //        b) Pop top element and check if it matches the closing bracket.
        //           If it doesn't match, return false.
        // 3. After traversal, if stack is empty, all brackets matched → return true.
        // 4. Otherwise, return false.

        stack<char> st;         // Stack to store opening brackets
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]); // Push opening bracket
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (st.empty()) return false; // No matching opening bracket

                char ch = st.top();   // Get top element
                st.pop();             // Remove it

                // Check if brackets match
                if ((s[i] == ')' && ch != '(') || 
                    (s[i] == ']' && ch != '[') || 
                    (s[i] == '}' && ch != '{')) 
                    return false;
                else 
                    continue;
            }
        }

        // If stack is empty, all brackets matched
        return st.empty();
    }
};

/*
Time Complexity (TC): O(n)
- We traverse the string once, n = s.size().
- Stack operations (push, pop, top) are O(1) each.

Space Complexity (SC): O(n)
- In worst case (all opening brackets), stack stores all n characters.
*/
