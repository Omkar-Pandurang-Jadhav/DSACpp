/*
QUESTION:
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

Example:
Input: x = 2.0, n = 10
Output: 1024.0

-----------------------------------------------------

APPROACH (Binary Exponentiation / Fast Power):

Step 1: Handle negative exponent
--------------------------------------
- If n is negative:
    → Convert n to positive using long long (to handle INT_MIN)
    → Final answer will be 1 / result

--------------------------------------

Step 2: Use binary exponentiation
--------------------------------------
- While n > 0:
    - If n is odd:
        → Multiply answer with x
        → Decrease n by 1
    - Else:
        → Square x
        → Divide n by 2

This reduces the exponent quickly (logarithmic steps)

--------------------------------------

WHY IT WORKS:
--------------------------------------
- Based on:
    x^n = (x^2)^(n/2)  if n is even
    x^n = x * x^(n-1)  if n is odd

-----------------------------------------------------

TIME COMPLEXITY:
O(log n)

→ Exponent reduces by half each step

-----------------------------------------------------

SPACE COMPLEXITY:
O(1)

→ No extra space used

-----------------------------------------------------

EDGE CASES:
--------------------------------------
- n = 0 → return 1
- n < 0 → return 1 / ans
- n = INT_MIN → handled using long long

-----------------------------------------------------
*/

class Solution {
public:
    double myPow(double x, int n) {

        long long nn = n;

        // Handle negative exponent safely
        if (nn < 0) nn = -nn;

        double ans = 1.0;

        // Binary exponentiation
        while (nn > 0) {
            if (nn % 2 == 1) {
                ans = ans * x;
                nn = nn - 1;
            } else {
                x = x * x;
                nn = nn / 2;
            }
        }

        // If original n was negative
        if (n < 0) return 1.0 / ans;

        return ans;
    }
};