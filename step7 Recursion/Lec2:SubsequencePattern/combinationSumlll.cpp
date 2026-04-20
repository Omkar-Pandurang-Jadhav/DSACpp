/*
QUESTION:
Find all valid combinations of k numbers that sum up to n such that:
- Only numbers from 1 to 9 are used
- Each number is used at most once

Example:
Input: k = 3, n = 7
Output: [[1,2,4]]

-----------------------------------------------------

APPROACH (Recursion + Backtracking - Pick / Not Pick):

Step 1: Generate numbers from 1 to 9
--------------------------------------
- These are the only allowed values

--------------------------------------

Step 2: At each index i, we have 2 choices:
--------------------------------------
1. Pick arr[i] → reduce target (n)
2. Not pick arr[i]

--------------------------------------

Step 3: Base condition
--------------------------------------
- If i >= arr.size():
    → Check:
        list.size() == k AND n == 0
    → If yes → valid combination

--------------------------------------

Step 4: Recursive flow
--------------------------------------
- If arr[i] <= n:
    → Pick element
    → Move to next index (i+1)

- Backtrack

- Not pick:
    → Move to next index

-----------------------------------------------------

WHY IT WORKS:
--------------------------------------
- Explores all subsets of numbers 1 to 9
- Filters those with exactly k elements and sum n

-----------------------------------------------------

TIME COMPLEXITY:
O(2^9) ≈ O(1)

→ Only 9 elements → constant bound

-----------------------------------------------------

SPACE COMPLEXITY:
O(k)

→ Recursion depth (max k elements in list)

-----------------------------------------------------

NOTE (IMPORTANT):
--------------------------------------
- Each element can be used only once → (i+1)
- No duplicates because numbers are unique
- Can be optimized by pruning early:
    if(n < 0) return;

-----------------------------------------------------
*/

class Solution {
public:
    void function(int i, vector<vector<int>> &ans, vector<int>& list,
                  vector<int> &arr, int k, int n){

        if(i >= arr.size()){
            if(list.size() == k && n == 0){
                ans.push_back(list);
            }
            return;
        }

        // Pick element
        if(arr[i] <= n){
            list.push_back(arr[i]);
            function(i + 1, ans, list, arr, k, n - arr[i]);
            list.pop_back();
        }

        // Not pick
        function(i + 1, ans, list, arr, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> nums;

        // Only numbers from 1 to 9
        for(int i = 1; i <= 9; i++){
            nums.push_back(i);
        }

        vector<vector<int>> ans;
        vector<int> list;

        function(0, ans, list, nums, k, n);

        return ans;
    }
};