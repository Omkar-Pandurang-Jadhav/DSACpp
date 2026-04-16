/*
QUESTION:
A digit string is called "good" if:
- Digits at even indices (0-based) are even → (0,2,4,6,8) → 5 choices
- Digits at odd indices are prime → (2,3,5,7) → 4 choices

Given n (length of string), return number of good digit strings of length n.

-----------------------------------------------------

APPROACH (Math + Recursive Binary Exponentiation):

Step 1: Count positions
--------------------------------------
- Even indices:
    even = (n + 1) / 2
- Odd indices:
    odd = n / 2

--------------------------------------

Step 2: Total combinations
--------------------------------------
- Even positions → 5 choices
- Odd positions → 4 choices

Total = (5^even) * (4^odd)

--------------------------------------

Step 3: Compute power using recursion
--------------------------------------
- Use binary exponentiation:
    - If p is even:
        x^p = (x^(p/2)) * (x^(p/2))
    - If p is odd:
        x^p = (x^(p/2)) * (x^(p/2)) * x

- Compute only once → reuse result

-----------------------------------------------------

TIME COMPLEXITY:
O(log n)

→ Exponent reduces by half each step

-----------------------------------------------------

SPACE COMPLEXITY:
O(log n)

→ Recursive stack

-----------------------------------------------------

EDGE CASES:
--------------------------------------
- n = 1 → only even position
- Large n → handled using modulo
- Avoid overflow using % mod

-----------------------------------------------------
*/

class Solution {
public:
    long long mod = 1e9 + 7;

    // Recursive binary exponentiation
    long long power(int num, long long p) {

        if (p <= 0) return 1;
        if (p == 1) return num;

        long long even, odd;

        if (p % 2 == 0) even = p / 2;
        else even = p / 2 + 1;

        odd = p / 2;

        long long ans = power(num, odd) % mod;

        if (even == odd)
            ans = ((ans % mod) * (ans % mod)) % mod;
        else
            ans = ((ans % mod) * (ans % mod) * (num % mod)) % mod;

        return ans % mod;
    }

    int countGoodNumbers(long long n) {

        long long even, odd;

        if (n % 2 == 0) even = n / 2;
        else even = n / 2 + 1;

        odd = n / 2;

        long long ans = (power(5, even) % mod * power(4, odd) % mod) % mod;

        return ans;
    }
};