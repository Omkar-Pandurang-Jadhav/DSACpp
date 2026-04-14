/*
QUESTION:
Given an integer array nums where:
- Every element appears exactly 3 times except for one element
- That one element appears only once

Find the single element that appears only once.

Example:
Input: nums = [2,2,3,2]
Output: 3

-----------------------------------------------------

APPROACH (Bit Manipulation - Finite State Machine idea):

We use three variables:
- one   -> stores bits which have appeared 1 time
- two   -> stores bits which have appeared 2 times
- three -> (not really needed but included in your logic)

Core idea:
We track count of bits modulo 3.

For every number:
1. Add bits to 'one' if seen first time
2. Move bits to 'two' if seen second time
3. Remove bits when seen third time

Key transitions:
- one = (one ^ num) & (~two)
- two = (two ^ num) & (~one)

This ensures:
- bits appearing 3 times are removed automatically

NOTE:
'three' is redundant here and not needed in optimal solution.

-----------------------------------------------------

WHY IT WORKS:
Each bit is tracked independently.
We simulate a counter (mod 3) using bitwise operations.

-----------------------------------------------------

TIME COMPLEXITY:
O(n)
→ We traverse the array once

SPACE COMPLEXITY:
O(1)
→ Only a few variables used (no extra space)

-----------------------------------------------------
*/


/* Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
 
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0;   // bits appeared once
        int two = 0;   // bits appeared twice
        int three = 0; // redundant (not needed)

        for(int i = 0; i < nums.size(); i++) {
            one = (one ^ nums[i]) & (~two);
            two = (~one) & (two ^ nums[i]);
            three = (~two) & (three ^ nums[i]); // unnecessary
        }

        return one;
    }
};  