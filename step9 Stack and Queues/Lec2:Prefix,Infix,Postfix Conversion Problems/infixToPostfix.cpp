#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    // ✅ Function to check if a character is an operator
    bool isOperator(char ch){
        if(ch=='*' || ch=='^' || ch=='-' || ch=='+' || ch=='/') return true;
        return false;
    }

    // ✅ Function to return precedence of operators
    int orderOfOperator(char ch){
        if(ch=='^') return 2;                 // Highest precedence
        else if(ch=='/' || ch=='*') return 1; // Medium precedence
        else if(ch=='+' || ch=='-') return 0; // Lowest precedence
        else return -1;
    }

    // ✅ Convert Infix expression to Postfix expression
    string infixToPostfix(string& s) {
        string ans = "";      // Final postfix result
        stack<char> st;       // Stack to hold operators
        int n = s.size();     

        for(int i = 0; i < n; i++) {
            // 🔹 If character is operand (A-Z, a-z, 0-9), add to output
            if(!isOperator(s[i]) && s[i] != '(' && s[i] != ')'){
                ans += s[i];
            }

            // 🔹 If character is operator
            else if(isOperator(s[i])){
                // Pop all operators with higher or equal precedence
                // (except when operator is '^' which is right-associative)
                while(!st.empty() && orderOfOperator(s[i]) <= orderOfOperator(st.top()) && s[i] != '^'){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }

            // 🔹 If '(' → push to stack
            else if(s[i] == '(') st.push('(');

            // 🔹 If ')' → pop till '('
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // Pop '('
            }
        }

        // 🔹 Pop remaining operators
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

/*
-------------------------------------------
🧠 Explanation:
-------------------------------------------
1. Operands (A, B, C, etc.) → directly added to output.
2. '(' → pushed to stack.
3. ')' → pop all operators till '('.
4. Operators:
   - Pop operators from stack with greater or equal precedence.
   - Push current operator.
5. At end → pop all remaining operators to output.

-------------------------------------------
⏱️ Time Complexity: O(n)
-------------------------------------------
- Each character in the input string is processed once.
- Each operator is pushed and popped at most once.

-------------------------------------------
💾 Space Complexity: O(n)
-------------------------------------------
- Stack can hold up to 'n' characters in the worst case 
  (like when expression starts with many '(' or operators).
-------------------------------------------
*/
