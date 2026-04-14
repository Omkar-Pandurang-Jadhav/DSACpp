/*
QUESTION:
Given two integers L and R, count the number of prime numbers in the range [L, R].

Example:
Input: L = 1, R = 10
Output: 4   (2, 3, 5, 7)

-----------------------------------------------------

APPROACH (Sieve of Eratosthenes):

Step 1: Initialize array
--------------------------------------
- Create an array 'prime' of size (R + 1)
- Initialize all values as 1 (assume prime)
- Mark 0 and 1 as non-prime

--------------------------------------

Step 2: Apply Sieve
--------------------------------------
- For i from 2 to √R:
    - If i is prime:
        - Mark all multiples of i from i*i to R as non-prime

Why start from i*i?
- Smaller multiples are already handled

--------------------------------------

Step 3: Count primes in range [L, R]
--------------------------------------
- Traverse from L to R
- Count elements marked as prime

-----------------------------------------------------

TIME COMPLEXITY:
O(R log log R)

→ Efficient sieve complexity

-----------------------------------------------------

SPACE COMPLEXITY:
O(R)

→ Extra array of size R+1

-----------------------------------------------------

NOTES (IMPORTANT):
--------------------------------------
- Always mark prime[0] and prime[1] = 0
- This solution is efficient for moderate R (≤ 10^7 approx)
- For very large R → use Segmented Sieve

-----------------------------------------------------
*/

class Solution {
public:
    int countPrimes(int L, int R) {

        // Step 1: Initialize
        vector<int> prime(R + 1, 1);
        prime[0] = prime[1] = 0;

        // Step 2: Sieve
        for (int i = 2; i * i <= R; i++) {
            if (prime[i] == 1) {
                for (int j = i * i; j <= R; j += i) {
                    prime[j] = 0;
                }
            }
        }

        // Step 3: Count primes in range
        int cnt = 0;
        for (int i = L; i <= R; i++) {
            if (prime[i] == 1) cnt++;
        }

        return cnt;
    }
};





/*
Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n+1,1);
        if(n==0 || n==1) return 0;
        
        for(int i=2;i*i<=n;i++){
            if(prime[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(prime[i]==1) cnt++;
        }
        return cnt;
    }
};