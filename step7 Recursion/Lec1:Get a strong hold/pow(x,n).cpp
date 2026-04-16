/*
QUESTION:
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

-----------------------------------------------------

APPROACH (Recursive Binary Exponentiation):

We use recursion + divide and conquer.

Step 1: Handle negative exponent
--------------------------------------
- Convert n to long long
- If n < 0 → make it positive
- Final answer = 1 / result

--------------------------------------

Step 2: Recursive function power(x, n, ans)
--------------------------------------
- Base case:
    if n <= 0 → return accumulated answer

- If n is odd:
    → Multiply ans with x
    → Reduce problem to power(x, n-1, ans*x)

- If n is even:
    → Square x
    → Reduce problem to power(x*x, n/2, ans)

--------------------------------------

WHY IT WORKS:
--------------------------------------
- Based on:
    x^n = x * x^(n-1)   (if n is odd)
    x^n = (x^2)^(n/2)  (if n is even)

- Each recursive call reduces n significantly → logarithmic depth

-----------------------------------------------------

TIME COMPLEXITY:
O(log n)

→ n gets halved in even case

-----------------------------------------------------

SPACE COMPLEXITY:
O(log n)

→ Recursive call stack

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
    // Recursive helper function
    double power(double x, long long n, double ans) {
        if (n <= 0) return ans;

        if (n % 2 == 1) {
            return power(x, n - 1, ans * x);
        } else {
            return power(x * x, n / 2, ans);
        }
    }

    double myPow(double x, int n) {
        long long nn = n;

        // Handle negative exponent
        if (nn < 0) nn = -nn;

        double ans = 1.0;

        // Compute power
        ans = power(x, nn, ans);

        // If original n was negative
        if (n < 0) return 1.0 / ans;

        return ans;
    }
};