/*
QUESTION:
Given an array arr of size n and an integer k,
check if there exists a subsequence whose sum is equal to k.

Example:
Input: arr = [1,2,3], k = 5
Output: true   (subsequence: [2,3])

-----------------------------------------------------

APPROACH (Recursion + Backtracking - Pick / Not Pick):

Step 1: At each index i, we have 2 choices:
--------------------------------------
1. Pick arr[i] → add to sum
2. Not pick arr[i]

--------------------------------------

Step 2: Base condition
--------------------------------------
- If i >= n:
    → Check if sum == k
    → If yes → return true
    → Else → return false

--------------------------------------

Step 3: Recursive flow
--------------------------------------
- Add current element → call recursion
- Backtrack (remove element)
- Skip current element → call recursion

--------------------------------------

Step 4: Optimization
--------------------------------------
- If any path returns true → stop immediately

-----------------------------------------------------

WHY IT WORKS:
--------------------------------------
- Generates all subsequences (2^n)
- Checks if any subsequence satisfies sum == k

-----------------------------------------------------

TIME COMPLEXITY:
O(2^n)

→ Each element has 2 choices

-----------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ Recursion stack depth

-----------------------------------------------------

NOTE:
--------------------------------------
- This is classic subset sum (recursion version)
- Can be optimized using DP (memoization / tabulation)

-----------------------------------------------------
*/

class Solution {
public:
    bool isSub(int i, vector<int>& arr, int k, int sum) {

        if(i >= arr.size()){
            if(sum == k) return true;
            return false;
        }

        // Pick element
        sum += arr[i];
        if(isSub(i + 1, arr, k, sum)) return true;

        // Backtrack
        sum -= arr[i];

        // Not pick
        if(isSub(i + 1, arr, k, sum)) return true;

        return false;
    }

    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return isSub(0, arr, k, 0);
    }
};