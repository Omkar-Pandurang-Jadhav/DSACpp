/*
QUESTION:
Given an array nums of distinct integers,
return all possible permutations.

Example:
Input: nums = [1,2,3]
Output:
[
 [1,2,3], [1,3,2],
 [2,1,3], [2,3,1],
 [3,1,2], [3,2,1]
]

-----------------------------------------------------

APPROACH (Backtracking + Visited Array):

Step 1: Use a visited array
--------------------------------------
- Track which elements are already used in current permutation

--------------------------------------

Step 2: Build permutation step by step
--------------------------------------
- At each step:
    → Try all unused elements
    → Mark as visited
    → Add to current list

--------------------------------------

Step 3: Base condition
--------------------------------------
- If list size == nums size:
    → One permutation complete

--------------------------------------

Step 4: Backtracking
--------------------------------------
- Remove last element
- Mark it unvisited

-----------------------------------------------------

WHY IT WORKS:
--------------------------------------
- Ensures each element is used exactly once per permutation
- Explores all possible orderings

-----------------------------------------------------

TIME COMPLEXITY:
O(n! * n)

→ n! permutations
→ Each takes O(n) to store

-----------------------------------------------------

SPACE COMPLEXITY:
O(n)+O(n)

→ Recursion stack + visited array

-----------------------------------------------------

NOTE:
--------------------------------------
- Works because elements are distinct
- For duplicates → need extra condition

-----------------------------------------------------
*/

class Solution {
public:
    void function(vector<vector<int>> &ans, vector<int> &list, vector<bool> &vis, vector<int> &nums) {

        // Base case
        if(list.size() == nums.size()){
            ans.push_back(list);
            return;
        }

        for(int i = 0; i < nums.size(); i++){

            if(!vis[i]){
                vis[i] = true;
                list.push_back(nums[i]);

                function(ans, list, vis, nums);

                // Backtrack
                list.pop_back();
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> list;

        vector<bool> vis(nums.size(), false);

        function(ans, list, vis, nums);

        return ans;
    }
};



/*
QUESTION:
Given an array nums of distinct integers,
return all possible permutations.

Example:
Input: nums = [1,2,3]
Output:
[
 [1,2,3], [1,3,2],
 [2,1,3], [2,3,1],
 [3,1,2], [3,2,1]
]

-----------------------------------------------------

APPROACH (Backtracking + In-place Swapping):

Step 1: Fix one position at a time
--------------------------------------
- Start from index = 0
- For each position:
    → Try placing every remaining element

--------------------------------------

Step 2: Swap elements
--------------------------------------
- Swap current index with i
- This fixes one element at current position

--------------------------------------

Step 3: Recursive call
--------------------------------------
- Move to next index → index + 1

--------------------------------------

Step 4: Backtracking
--------------------------------------
- Swap back to restore original array

--------------------------------------

Step 5: Base condition
--------------------------------------
- If index == n:
    → One permutation is formed

-----------------------------------------------------

WHY IT WORKS:
--------------------------------------
- At each level, we choose one element for that position
- Recursively generate all permutations

-----------------------------------------------------

TIME COMPLEXITY:
O(n! * n)

→ n! permutations
→ Each permutation takes O(n) to copy/store

-----------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ Recursion stack depth

-----------------------------------------------------

NOTE (IMPORTANT):
--------------------------------------
- No extra visited array needed
- In-place modification → space efficient

- You can directly do:
    ans.push_back(arr);
  instead of manually copying

-----------------------------------------------------
*/

class Solution {
public:
    void function(int index, vector<vector<int>> &ans, vector<int> &arr) {

        // Base case
        if(index == arr.size()){
            vector<int> list;
            for(int i = 0; i < arr.size(); i++){
                list.push_back(arr[i]);
            }
            ans.push_back(list);
            return;
        }

        for(int i = index; i < arr.size(); i++){

            // Swap to fix element
            swap(arr[i], arr[index]);

            // Recurse for next index
            function(index + 1, ans, arr);

            // Backtrack
            swap(arr[i], arr[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        function(0, ans, nums);

        return ans;
    }
};