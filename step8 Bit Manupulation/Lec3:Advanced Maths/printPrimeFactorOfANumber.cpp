/*
QUESTION:
Given a number n, find its largest prime factor.

Example:
Input: n = 100
Output: 5

-----------------------------------------------------

APPROACH:

We use trial division to find prime factors.

Step 1: Start checking from i = 2 to sqrt(n)
--------------------------------------------
- If i divides n, then i is a factor
- Keep dividing n by i until it's no longer divisible
  → This removes all occurrences of that factor

- Keep updating 'ans' with i
  → So the latest (largest) factor is stored

--------------------------------------------

Step 2: Why go till sqrt(n)?
--------------------------------------------
- If n has a factor greater than sqrt(n),
  then the corresponding smaller factor must already be checked

--------------------------------------------

Step 3: Handle remaining n
--------------------------------------------
After loop:
- If n > 1 → it means n itself is a prime number
- This remaining n is the largest prime factor

-----------------------------------------------------

TIME COMPLEXITY:
O(√n)
→ Loop runs till sqrt(n)

SPACE COMPLEXITY:
O(1)
→ No extra space used

-----------------------------------------------------
*/

class Solution {
  public:
    int largestPrimeFactor(int n) {
        int ans = 0;

        // Check factors from 2 to sqrt(n)
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                ans = i;

                // Remove all occurrences of factor i
                while(n % i == 0){
                    n = n / i;
                }
            }
        }

        // If n is still > 1, it is a prime factor
        if(n != 1) ans = n;

        return ans;
    }
};