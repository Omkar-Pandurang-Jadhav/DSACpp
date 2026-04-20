/*
QUESTION:
Given an array arr, return the sum of all possible subsets.

Example:
Input: arr = [1,2]
Output: [0,1,2,3]

Subsets:
[] → 0
[1] → 1
[2] → 2
[1,2] → 3

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
    → Store current sum in answer
    → Return

--------------------------------------

Step 3: Recursive flow
--------------------------------------
- Include current element → add to sum → recurse
- Backtrack (remove element)
- Exclude current element → recurse

-----------------------------------------------------

WHY IT WORKS:
--------------------------------------
- Generates all subsets (2^n)
- Stores sum of each subset

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
- This is variation of subset generation
- Instead of storing subset → store sum

- Output is usually sorted in some platforms
  → Can add: sort(ans.begin(), ans.end());

-----------------------------------------------------
*/

class Solution {
public:
    void function(int i, vector<int> &ans, vector<int>& arr, int sum) {

        if(i >= arr.size()){
            ans.push_back(sum);
            return;
        }

        // Pick element
        sum += arr[i];
        function(i + 1, ans, arr, sum);

        // Backtrack
        sum -= arr[i];

        // Not pick
        function(i + 1, ans, arr, sum);
    }

    vector<int> subsetSums(vector<int>& arr) {

        vector<int> ans;

        function(0, ans, arr, 0);

        return ans;
    }
};