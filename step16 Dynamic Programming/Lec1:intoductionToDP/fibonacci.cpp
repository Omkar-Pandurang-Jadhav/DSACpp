/*
============================================================
FIBONACCI - 3 APPROACHES (MEMOIZATION, TABULATION, SPACE OPTIMIZED)
============================================================

------------------------------------------------------------
1️⃣ MEMOIZATION (Top-Down DP + Recursion)
------------------------------------------------------------

APPROACH:
- Use recursion to compute Fibonacci
- Store already computed values in dp[]
- Avoid recomputation of same subproblems

LOGIC:
F(n) = F(n-1) + F(n-2)

------------------------------------------------------------

TIME COMPLEXITY:
O(n)
→ Each state (0 to n) computed only once

------------------------------------------------------------

SPACE COMPLEXITY:
O(n) + O(n) = O(n)

Breakdown:
- dp array → O(n)
- recursion stack → O(n)

------------------------------------------------------------
*/

class Solution {
  public:
    int function(int n, vector<int> &dp){
        if(n <= 1) return n;

        if(dp[n] != -1) return dp[n];

        return dp[n] = function(n-1, dp) + function(n-2, dp);
    }

    int nthFibonacci(int n) {
        vector<int> dp(n+1, -1);
        return function(n, dp);
    }
};



/*
------------------------------------------------------------
2️⃣ TABULATION (Bottom-Up DP)
------------------------------------------------------------

APPROACH:
- Build solution iteratively from 0 → n
- No recursion
- Store results in dp array

LOGIC:
dp[0] = 0
dp[1] = 1
dp[i] = dp[i-1] + dp[i-2]

------------------------------------------------------------

TIME COMPLEXITY:
O(n)
→ Single loop from 2 to n

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

Breakdown:
- dp array → O(n)
- recursion stack → NOT USED (O(0))

------------------------------------------------------------
*/

class Solution {
  public:
    int nthFibonacci(int n) {

        vector<int> dp(n+1, -1);

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};



/*
------------------------------------------------------------
3️⃣ SPACE OPTIMIZED (Best Approach)
------------------------------------------------------------

APPROACH:
- Observe that we only need last 2 values
- No need for full dp array

LOGIC:
prev2 = F(n-2)
prev  = F(n-1)
cur   = prev + prev2

------------------------------------------------------------

TIME COMPLEXITY:
O(n)
→ Single loop

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

Breakdown:
- No dp array
- No recursion stack
- Only 3 variables used

------------------------------------------------------------
*/

class Solution {
  public:
    int nthFibonacci(int n) {

        if(n == 0 || n == 1) return n;

        int prev2 = 0;
        int prev  = 1;
        int cur   = 0;

        for(int i = 2; i <= n; i++){
            cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }

        return cur;
    }
};


/*
============================================================
FINAL COMPARISON (VERY IMPORTANT FOR EXAMS / INTERVIEW)
============================================================

| Approach        | Time  | Space (Total) | Stack Space |
|----------------|------|---------------|-------------|
| Memoization    | O(n) | O(n)          | O(n)        |
| Tabulation     | O(n) | O(n)          | O(0)        |
| Space Optimized| O(n) | O(1)          | O(0)        |

============================================================

KEY TAKEAWAYS:
- Memoization → easy to write, uses recursion
- Tabulation → iterative, no recursion overhead
- Space optimized → BEST (minimal memory)

============================================================
*/