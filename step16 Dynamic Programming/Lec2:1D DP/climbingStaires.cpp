/*
============================================================
CLIMBING STAIRS - 3 APPROACHES
(MEMOIZATION, TABULATION, SPACE OPTIMIZED)
============================================================

PROBLEM:
You are climbing a staircase. It takes n steps to reach the top.
Each time you can climb either 1 step or 2 steps.
Return the number of distinct ways to reach the top.

Relation:
ways(n) = ways(n-1) + ways(n-2)
👉 Same as Fibonacci (shifted base case)

Base:
ways(0) = 1  (1 way: stay)
ways(1) = 1

============================================================


------------------------------------------------------------
1️⃣ MEMOIZATION (Top-Down DP + Recursion)
------------------------------------------------------------

APPROACH:
- Use recursion
- Store results in dp[] to avoid recomputation

TIME COMPLEXITY:
O(n)
→ Each state computed once

SPACE COMPLEXITY:
O(n) + O(n) = O(n)
→ dp array: O(n)
→ recursion stack: O(n)

------------------------------------------------------------
*/

class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n <= 1) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};



/*
------------------------------------------------------------
2️⃣ TABULATION (Bottom-Up DP)
------------------------------------------------------------

APPROACH:
- Build solution iteratively from 0 → n
- No recursion

TIME COMPLEXITY:
O(n)
→ Single loop

SPACE COMPLEXITY:
O(n)
→ dp array
→ No recursion stack

------------------------------------------------------------
*/

class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n+1, -1);

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};



/*
------------------------------------------------------------
3️⃣ SPACE OPTIMIZED (BEST APPROACH)
------------------------------------------------------------

APPROACH:
- Only last two states needed
- Use variables instead of array

TIME COMPLEXITY:
O(n)

SPACE COMPLEXITY:
O(1)
→ No array
→ No recursion stack

------------------------------------------------------------
*/

class Solution {
public:
    int climbStairs(int n) {

        if(n <= 1) return 1;

        int prev2 = 1;  // ways(0)
        int prev  = 1;  // ways(1)
        int cur   = 0;

        for(int i = 2; i <= n; i++){
            cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }

        return prev;
    }
};



/*
============================================================
FINAL COMPARISON (IMPORTANT)
============================================================

| Approach        | Time  | Space (Total) | Stack Space |
|----------------|------|---------------|-------------|
| Memoization    | O(n) | O(n)          | O(n)        |
| Tabulation     | O(n) | O(n)          | O(0)        |
| Space Optimized| O(n) | O(1)          | O(0)        |

============================================================

KEY TAKEAWAYS:
- Same pattern as Fibonacci
- Memoization → easiest but uses recursion
- Tabulation → iterative DP
- Space optimized → BEST (used in interviews)

============================================================
*/