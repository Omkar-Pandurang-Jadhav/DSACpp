/*
============================================================
FROG JUMP (MIN COST) - 4 APPROACHES
(Recursion, Memoization, Tabulation, Space Optimized)
============================================================

PROBLEM:
Given heights[], frog can jump:
- 1 step or 2 steps
Cost = abs(height[j] - height[i])
Find minimum cost to reach last index

============================================================


------------------------------------------------------------
1️⃣ PURE RECURSION (Top-Down without DP)
------------------------------------------------------------

APPROACH:
- From index i:
    → Jump from i-1
    → Jump from i-2
- Take minimum of both

------------------------------------------------------------

TIME COMPLEXITY:
O(2^n) ❌
→ Each index branches into 2 calls

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)
→ Recursion stack depth

------------------------------------------------------------
*/

class Solution {
  public:
    int function(int i, vector<int> &height){
        if(i <= 0) return 0;

        int left, right = INT_MAX;

        if(i > 0)
            left = function(i-1, height)
                   + abs(height[i] - height[i-1]);

        if(i > 1)
            right = function(i-2, height)
                    + abs(height[i] - height[i-2]);

        return min(left, right);
    }

    int minCost(vector<int>& height) {
        return function(height.size()-1, height);
    }
};



/*
------------------------------------------------------------
2️⃣ MEMOIZATION (Top-Down DP)
------------------------------------------------------------

APPROACH:
- Same recursion
- Store results in dp[] to avoid recomputation

------------------------------------------------------------

TIME COMPLEXITY:
O(n)
→ Each state computed once

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
    int function(int i, vector<int> &height, vector<int> &dp){

        if(i <= 0) return 0;

        if(dp[i] != -1) return dp[i];

        int left, right = INT_MAX;

        if(i > 0)
            left = function(i-1, height, dp)
                   + abs(height[i] - height[i-1]);

        if(i > 1)
            right = function(i-2, height, dp)
                    + abs(height[i] - height[i-2]);

        return dp[i] = min(left, right);
    }

    int minCost(vector<int>& height) {

        vector<int> dp(height.size(), -1);

        return function(height.size()-1, height, dp);
    }
};



/*
------------------------------------------------------------
3️⃣ TABULATION (Bottom-Up DP)
------------------------------------------------------------

APPROACH:
- Build dp[] iteratively
- dp[i] = min cost to reach i

------------------------------------------------------------

TIME COMPLEXITY:
O(n)
→ Single loop

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)
→ dp array
→ No recursion stack

------------------------------------------------------------
*/

class Solution {
  public:
    int minCost(vector<int>& height) {

        int n = height.size();

        vector<int> dp(n);

        dp[0] = 0;

        if(n > 1)
            dp[1] = abs(height[1] - height[0]);

        for(int i = 2; i < n; i++){
            dp[i] = min(
                dp[i-1] + abs(height[i] - height[i-1]),
                dp[i-2] + abs(height[i] - height[i-2])
            );
        }

        return dp[n-1];
    }
};



/*
------------------------------------------------------------
4️⃣ SPACE OPTIMIZED (BEST)
------------------------------------------------------------

APPROACH:
- Only need last two states
- No dp array

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)
→ Only 3 variables
→ No recursion stack

------------------------------------------------------------
*/

class Solution {
  public:
    int minCost(vector<int>& height) {

        int n = height.size();

        if(n == 1) return 0;

        int prev2 = 0;
        int prev  = abs(height[1] - height[0]);
        int cur   = prev;

        for(int i = 2; i < n; i++){
            cur = min(
                prev + abs(height[i] - height[i-1]),
                prev2 + abs(height[i] - height[i-2])
            );

            prev2 = prev;
            prev = cur;
        }

        return cur;
    }
};



/*
============================================================
FINAL COMPARISON (VERY IMPORTANT)
============================================================

| Approach        | Time    | Space (Total) | Stack Space |
|----------------|---------|---------------|-------------|
| Recursion      | O(2^n)  | O(n)          | O(n)        |
| Memoization    | O(n)    | O(n)          | O(n)        |
| Tabulation     | O(n)    | O(n)          | O(0)        |
| Space Optimized| O(n)    | O(1)          | O(0)        |

============================================================

KEY TAKEAWAYS:
- Recursion → simplest but inefficient
- Memoization → avoids recomputation
- Tabulation → iterative DP
- Space optimized → BEST (used in interviews)

============================================================
*/