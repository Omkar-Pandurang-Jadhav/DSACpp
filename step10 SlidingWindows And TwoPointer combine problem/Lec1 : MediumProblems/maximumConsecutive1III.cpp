/*Given a binary array nums and an integer k, return the maximum number 
of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.*/


/*
============================================================
MAX CONSECUTIVE ONES III (3 APPROACHES)
============================================================

PROBLEM:
Given a binary array nums and an integer k,
return the maximum number of consecutive 1's
if you can flip at most k zeros.

============================================================


------------------------------------------------------------
1️⃣ BRUTE FORCE (Nested Loops)
------------------------------------------------------------

APPROACH:
- Fix starting index i
- Extend subarray using j
- Count number of zeros
- If zeros ≤ k → update max length
- Else break

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2)

→ Outer loop runs n times
→ Inner loop runs up to n

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

------------------------------------------------------------
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int maxlen = 0;

        for(int i = 0; i < nums.size(); i++){

            int cnt = 0;

            for(int j = i; j < nums.size(); j++){

                if(nums[j] == 0) cnt++;

                if(cnt <= k){
                    maxlen = max(maxlen, j - i + 1);
                }
                else break;
            }
        }

        return maxlen;
    }
};



/*
------------------------------------------------------------
2️⃣ OPTIMAL (Sliding Window - STRICT, WHILE)
------------------------------------------------------------

APPROACH:
- Use two pointers (l, r)
- Expand r
- Count zeros
- If zeros > k:
    → shrink window using WHILE
- Always maintain valid window

------------------------------------------------------------

TIME COMPLEXITY:
O(2N)

→ r pointer moves N times
→ l pointer moves at most N times
→ Total operations ≤ 2N

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

------------------------------------------------------------

KEY INSIGHT:
- Window is ALWAYS valid
- Standard sliding window template

------------------------------------------------------------
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int cnt0 = 0;
        int l = 0, r = 0;
        int maxlen = 0;

        while(r < nums.size()){

            if(nums[r] == 0) cnt0++;

            while(cnt0 > k){
                if(nums[l] == 0) cnt0--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};



/*
------------------------------------------------------------
3️⃣ OPTIMAL (Sliding Window - RELAXED, IF)
------------------------------------------------------------

APPROACH:
- Same as sliding window
- Shrink only once using IF
- Window may be temporarily invalid

------------------------------------------------------------

TIME COMPLEXITY:
O(2N)

→ r moves N times
→ l moves at most N times
→ Total ≤ 2N

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

------------------------------------------------------------

KEY INSIGHT:
- Works for this problem specifically
- Not a general sliding window pattern

------------------------------------------------------------
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int cnt0 = 0;
        int l = 0, r = 0;
        int maxlen = 0;

        while(r < nums.size()){

            if(cnt0 > k){
                if(nums[l] == 0) cnt0--;
                l++;
            }

            if(nums[r] == 0) cnt0++;

            if(cnt0 <= k)
                maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};



/*
============================================================
FINAL COMPARISON
============================================================

| Approach              | Time Complexity | Space |
|----------------------|----------------|-------|
| Brute Force          | O(n^2) ❌      | O(1)  |
| Sliding Window (while)| O(2N) ⭐      | O(1)  |
| Sliding Window (if)  | O(2N) ⭐       | O(1)  |

============================================================

NOTE:
- O(2N) simplifies to O(N), but writing O(2N)
  shows exact pointer movement analysis

============================================================
*/


