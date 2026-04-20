/*
QUESTION:
Given an integer array nums, return all possible subsets (the power set).

Example:
Input: nums = [1,2,3]
Output:
[
 [], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]
]

-----------------------------------------------------

APPROACH (Recursion + Backtracking - Pick / Not Pick):

Step 1: At each index i, we have 2 choices:
--------------------------------------
1. Include nums[i] in the current subset
2. Exclude nums[i]

--------------------------------------

Step 2: Base condition
--------------------------------------
- If i >= nums.size():
    → We have formed one subset
    → Add it to answer

--------------------------------------

Step 3: Recursion flow
--------------------------------------
- Include current element → move to next index
- Backtrack (remove element)
- Exclude current element → move to next index

-----------------------------------------------------

WHY IT WORKS:
--------------------------------------
- Each element has 2 choices → include or exclude
- Total subsets = 2^n

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

NOTE:
--------------------------------------
- This is a classic Backtracking pattern
- Also called "Pick / Not Pick" technique

-----------------------------------------------------
*/

class Solution {
public:
    void function(int i, vector<vector<int>> &ans, vector<int> &list, vector<int>& nums) {

        if(i >= nums.size()){
            ans.push_back(list);
            return;
        }

        // Include current element
        list.push_back(nums[i]);
        function(i + 1, ans, list, nums);

        // Backtrack
        list.pop_back();

        // Exclude current element
        function(i + 1, ans, list, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> list;

        function(0, ans, list, nums);

        return ans;
    }
};