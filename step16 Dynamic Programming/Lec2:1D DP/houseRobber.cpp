/*
You are a professional robber planning to rob houses along a street.
 Each house has a certain amount of money stashed, the only constraint 
 stopping you from robbing each of them is that adjacent houses have security 
 systems connected and it will automatically contact the police if two adjacent 
 houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return 
the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.*/


/*
============================================================
HOUSE ROBBER - 4 APPROACHES
(Recursion, Memoization, Tabulation, Space Optimized)
============================================================

PROBLEM:
Given nums[], you cannot rob adjacent houses.
Find maximum money you can rob.

Relation:
f(i) = max(
    nums[i] + f(i-2),   // pick
    f(i-1)              // not pick
)

============================================================


------------------------------------------------------------
1️⃣ PURE RECURSION (Pick / Not Pick)
------------------------------------------------------------

APPROACH:
- At index i:
    → Pick → i-2
    → Not pick → i-1

------------------------------------------------------------

TIME COMPLEXITY:
O(2^n) ❌
→ Each index has 2 choices

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)
→ Recursion stack depth

------------------------------------------------------------
*/

class Solution {
public:
    int function(int i, vector<int>& nums){

        if(i < 0) return 0;
        if(i == 0) return nums[0];

        int pick = nums[i] + function(i - 2, nums);
        int notPick = function(i - 1, nums);

        return max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        return function(nums.size() - 1, nums);
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
    int function(int i, vector<int> &nums, vector<int> &dp){

        if(i < 0) return 0;
        if(i == 0) return dp[i];

        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + function(i-2, nums, dp);
        int notPick = function(i-1, nums, dp);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];

        return function(nums.size()-1, nums, dp);
    }
};



/*
------------------------------------------------------------
3️⃣ TABULATION (Bottom-Up DP)
------------------------------------------------------------

APPROACH:
- Build dp[] iteratively
- dp[i] = max money till index i

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)
→ dp array
→ No recursion stack

------------------------------------------------------------
*/

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n);

        dp[0] = nums[0];

        for(int i = 1; i < n; i++){
            int take = nums[i];
            if(i > 1) take += dp[i-2];

            int notTake = dp[i-1];

            dp[i] = max(take, notTake);
        }

        return dp[n-1];
    }
};



/*
------------------------------------------------------------
4️⃣ SPACE OPTIMIZED (BEST)
------------------------------------------------------------

APPROACH:
- Only last two states needed

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)
→ Only variables used

------------------------------------------------------------
*/

class Solution {
public:
    int rob(vector<int>& nums) {

        int prev  = nums[0]; // dp[i-1]
        int prev2 = 0;       // dp[i-2]

        for(int i = 1; i < nums.size(); i++){

            int take = nums[i];
            if(i > 1) take += prev2;

            int notTake = prev;

            int cur = max(take, notTake);

            prev2 = prev;
            prev = cur;
        }

        return prev;
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
- Recursion → simple but inefficient
- Memoization → avoids recomputation
- Tabulation → iterative DP
- Space optimized → BEST (interview preferred)

============================================================
*/