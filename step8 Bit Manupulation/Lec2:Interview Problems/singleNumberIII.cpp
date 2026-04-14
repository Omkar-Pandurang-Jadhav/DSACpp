

/*
QUESTION:
Given an array nums where:
- Exactly two elements appear only once
- All the other elements appear exactly twice

Find the two elements that appear only once.

-----------------------------------------------------

APPROACH (Bit Manipulation using XOR):

Step 1: XOR of all elements
--------------------------------
Take XOR of all numbers.

Let the two unique numbers be a and b.

XOR_all = a ^ b

Why?
- All duplicate numbers cancel out (x ^ x = 0)
- Only a ^ b remains

--------------------------------

Step 2: Find a distinguishing bit
--------------------------------
We need to separate a and b.

Find any bit where a and b differ.
We extract the rightmost set bit:

XOR = (XOR & (XOR - 1)) ^ XOR;

This gives a number with only one set bit (rightmost set bit of XOR_all)

--------------------------------

Step 3: Divide numbers into 2 groups
--------------------------------
Using that bit:

Group 1: numbers where this bit is set
Group 2: numbers where this bit is not set

- a and b will fall into different groups
- duplicate numbers still cancel out within each group

--------------------------------

Step 4: XOR within each group
--------------------------------
- XOR of group 1 → gives one unique number
- XOR of group 2 → gives the other unique number

-----------------------------------------------------

TIME COMPLEXITY:
O(n)
→ One pass for XOR
→ One pass for grouping

SPACE COMPLEXITY:
O(1)
→ No extra space used (excluding output)

-----------------------------------------------------
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XOR = 0;

        // Step 1: XOR of all elements
        for(int i = 0; i < nums.size(); i++){
            XOR = XOR ^ nums[i];
        }

        // Step 2: Get rightmost set bit (distinguishing bit)
        XOR = (XOR & (XOR - 1)) ^ XOR;

        int xor1 = 0;
        int xor2 = 0;

        // Step 3 & 4: Divide into 2 groups and XOR
        for(int i = 0; i < nums.size(); i++){
            if((nums[i] & XOR) == XOR)
                xor1 = xor1 ^ nums[i];
            else
                xor2 = xor2 ^ nums[i];
        }

        vector<int> ans;
        ans.push_back(xor1);
        ans.push_back(xor2);

        return ans;
    }
};