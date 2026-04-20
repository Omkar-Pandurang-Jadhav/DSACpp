/*
QUESTION:
Given an array of distinct integers (candidates) and a target,
return all unique combinations where the chosen numbers sum to target.

You can use the same number multiple times.

Example:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3], [7]]

-----------------------------------------------------

APPROACH (Recursion + Backtracking - Pick / Not Pick):

Step 1: At each index i, we have 2 choices:
--------------------------------------
1. Pick arr[i] → reduce target
   → Stay at same index (can reuse element)

2. Not pick arr[i]
   → Move to next index

--------------------------------------

Step 2: Base condition
--------------------------------------
- If i == arr.size():
    → If target == 0 → valid combination → store it
    → Return

--------------------------------------

Step 3: Recursive flow
--------------------------------------
- If arr[i] <= target:
    → Pick element
    → Call recursion with same index (i)

- Backtrack (remove element)

- Move to next index (not pick case)

-----------------------------------------------------

WHY IT WORKS:
--------------------------------------
- Explores all combinations
- Ensures reuse of elements when needed
- Avoids duplicates by fixed index traversal

-----------------------------------------------------

TIME COMPLEXITY:
Exponential (≈ O(2^n * k))

→ k = average length of combination

-----------------------------------------------------

SPACE COMPLEXITY:
O(k)

→ Recursion depth (depends on target)

-----------------------------------------------------

NOTE:
--------------------------------------
- This is classic "Combination Sum"
- Difference from subsets:
  → We can reuse same element (i does not increase)
- Works only because elements are positive

-----------------------------------------------------
*/

class Solution {
public:
    void function(int i, vector<vector<int>> &ans, vector<int> &list, vector<int> &arr, int target) {

        if(i == arr.size()){
            if(target == 0){
                ans.push_back(list);
            }
            return;
        }

        // Pick element (if possible)
        if(arr[i] <= target){
            list.push_back(arr[i]);
            function(i, ans, list, arr, target - arr[i]);
            list.pop_back();
        }

        // Not pick
        function(i + 1, ans, list, arr, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;

        function(0, ans, list, candidates, target);

        return ans;
    }
};