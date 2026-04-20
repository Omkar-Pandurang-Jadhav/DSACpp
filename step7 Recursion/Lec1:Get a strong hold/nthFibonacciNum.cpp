/*
QUESTION:
Given an integer n, find the nth Fibonacci number.

Fibonacci series:
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)

Example:
Input: n = 5
Output: 5   (0,1,1,2,3,5)

-----------------------------------------------------

APPROACH (Simple Recursion):

Step 1: Base cases
--------------------------------------
- If n <= 1 → return n

--------------------------------------

Step 2: Recursive relation
--------------------------------------
- F(n) = F(n-1) + F(n-2)

- Recursively compute both values

-----------------------------------------------------

WHY IT WORKS:
--------------------------------------
- Direct implementation of Fibonacci definition

-----------------------------------------------------

TIME COMPLEXITY:
O(2^n)

→ Exponential due to repeated computations

-----------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ Recursion stack depth

-----------------------------------------------------

MAJOR ISSUE (IMPORTANT):
--------------------------------------
- Same subproblems recomputed multiple times

Example:
F(5)
→ F(4) + F(3)
→ F(3) computed again ❌

-----------------------------------------------------

BETTER APPROACHES:
--------------------------------------
1. Memoization (Top-down DP) → O(n)
2. Tabulation (Bottom-up DP) → O(n)
3. Space Optimized → O(n) time, O(1) space (BEST)

-----------------------------------------------------
*/

class Solution {
public:
    int nthFibonacci(int n) {

        // Base case
        if (n <= 1) return n;

        // Recursive call
        return nthFibonacci(n - 1) + nthFibonacci(n - 2);
    }
};