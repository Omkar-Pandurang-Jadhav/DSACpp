/*
QUESTION:
Given an array arr and an integer k,
count the number of subsequences whose sum is equal to k.

Example:
Input: arr = [1,2,3], k = 3
Output: 2   ([1,2], [3])

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
    → If sum == k → increment count
    → Return

--------------------------------------

Step 3: Recursive flow
--------------------------------------
- Include current element → call recursion
- Backtrack (remove element)
- Exclude current element → call recursion

--------------------------------------

Step 4: Count all valid subsequences
--------------------------------------
- Unlike boolean version, we DO NOT stop early
- Explore all possibilities

-----------------------------------------------------

WHY IT WORKS:
--------------------------------------
- Generates all subsequences (2^n)
- Counts how many satisfy sum == k

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
- This is counting version of subset sum
- Cannot use early return (must explore all paths)
- Can be optimized using DP

-----------------------------------------------------
*/

void countSubsequences(int i, vector<int>& arr, int k, int &cnt, int sum) {

    if(i >= arr.size()){
        if(sum == k) cnt++;
        return;
    }

    // Pick element
    sum += arr[i];
    countSubsequences(i + 1, arr, k, cnt, sum);

    // Backtrack
    sum -= arr[i];

    // Not pick
    countSubsequences(i + 1, arr, k, cnt, sum);
}

int findWays(vector<int>& arr, int k){
    int cnt = 0;

    countSubsequences(0, arr, k, cnt, 0);

    return cnt;
}