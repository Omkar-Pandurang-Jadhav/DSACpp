/*
QUESTION:
Given an integer array nums that may contain duplicates,
return all possible subsets (the power set) without duplicate subsets.

Example:
Input: nums = [1,2,2]
Output:
[
 [], [1], [1,2], [1,2,2], [2], [2,2]
]

-----------------------------------------------------

APPROACH (Backtracking + Loop + Skip Duplicates):

Step 1: Sort the array
--------------------------------------
- Ensures duplicates are adjacent
- Helps in skipping duplicates efficiently

--------------------------------------

Step 2: Use loop-based recursion
--------------------------------------
- At each index:
    → Add current subset to answer
    → Try picking each element from current index onward

--------------------------------------

Step 3: Skip duplicates
--------------------------------------
Condition:
    if(i > index && arr[i] == arr[i-1]) continue;

- Prevents generating same subset multiple times

--------------------------------------

Step 4: Recursive flow
--------------------------------------
- Pick element
- Move to next index (i+1)
- Backtrack

-----------------------------------------------------

WHY IT WORKS:
--------------------------------------
- Loop ensures all possibilities explored
- Sorting + skip condition avoids duplicates

-----------------------------------------------------

TIME COMPLEXITY:
O(2^n * n)

→ 2^n subsets
→ Each subset copy takes O(n)

-----------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ Recursion stack depth

-----------------------------------------------------

NOTE (IMPORTANT):
--------------------------------------
- No need for explicit base case
  → Loop naturally handles termination

- This is optimal solution (no set needed)

-----------------------------------------------------
*/

class Solution {
public:
    void function(int index, vector<vector<int>>& ans, vector<int>& list, vector<int> &arr) {

        // Store current subset
        ans.push_back(list);

        for(int i = index; i < arr.size(); i++){

            // Skip duplicates
            if(i > index && arr[i] == arr[i-1]) continue;

            // Pick element
            list.push_back(arr[i]);

            function(i + 1, ans, list, arr);

            // Backtrack
            list.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Sort to handle duplicates
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> list;

        function(0, ans, list, nums);

        return ans;
    }
};