/*
QUESTION:
Given a collection of candidate numbers (candidates) and a target,
find all unique combinations where the chosen numbers sum to target.

Each number can be used AT MOST ONCE.

Example:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
 [1,1,6],
 [1,2,5],
 [1,7],
 [2,6]
]

-----------------------------------------------------

APPROACH (Backtracking + Sorting + Skip Duplicates):

Step 1: Sort the array
--------------------------------------
- Helps to:
    → Handle duplicates
    → Enable pruning (early stopping)

--------------------------------------

Step 2: Use recursion with loop
--------------------------------------
- Start from index
- For each element:
    → Pick element
    → Move to next index (i+1) → cannot reuse same element

--------------------------------------

Step 3: Skip duplicates
--------------------------------------
- If same element appears again at same level:
    → Skip it

Condition:
    if(i > index && arr[i] == arr[i-1]) continue;

--------------------------------------

Step 4: Pruning
--------------------------------------
- If arr[i] > target → stop loop (because sorted)

--------------------------------------

Step 5: Base condition
--------------------------------------
- If target == 0:
    → valid combination found

-----------------------------------------------------

WHY IT WORKS:
--------------------------------------
- Sorting ensures duplicates are adjacent
- Skipping prevents duplicate combinations
- Each element used once → i+1

-----------------------------------------------------

TIME COMPLEXITY:
O(2^n * k)

→ k = average length of combination

-----------------------------------------------------

SPACE COMPLEXITY:
O(k)

→ Recursion depth

-----------------------------------------------------

NOTE (IMPORTANT):
--------------------------------------
- Difference from Combination Sum 1:
    → Here elements cannot be reused
    → So recursive call uses (i+1)

- No need for set → duplicates handled efficiently

-----------------------------------------------------
*/

class Solution {
public:
    void function(int index, vector<vector<int>> &ans, vector<int> &list, vector<int> &arr, int target) {

        if(target == 0){
            ans.push_back(list);
            return;
        }

        for(int i = index; i < arr.size(); i++){

            // Skip duplicates
            if(i > index && arr[i] == arr[i - 1]) continue;

            // Pruning
            if(arr[i] > target) break;

            // Pick element
            list.push_back(arr[i]);

            function(i + 1, ans, list, arr, target - arr[i]);

            // Backtrack
            list.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;

        // Sort for duplicate handling + pruning
        sort(candidates.begin(), candidates.end());

        vector<int> list;

        function(0, ans, list, candidates, target);

        return ans;
    }
};