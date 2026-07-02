/*
Question:
You are given a 0-indexed integer array nums.

In one operation, you can choose any element of the array and
increment it by 1.

Return the minimum number of operations required to make the
array strictly increasing.

An array is strictly increasing if
nums[i] < nums[i + 1] for every valid index i.

Example 1:
Input: nums = [1,1,1]
Output: 3

Explanation:
Increment the elements to obtain [1,2,3].

Example 2:
Input: nums = [1,5,2,4,1]
Output: 14

Example 3:
Input: nums = [8]
Output: 0

Approach:
1. Traverse the array from left to right.
2. Compare every element with its previous element.
3. If the current element is already greater than the previous one,
   no operation is required.
4. Otherwise, the current element must be increased so that it becomes
   exactly one greater than the previous element.
5. The number of increments required is:
      nums[i - 1] - nums[i] + 1
6. Add these increments to the total answer.
7. Update the current element with its new value so that the remaining
   elements can be compared against the modified value.
8. Continue this process until the end of the array.
9. Return the total number of operations performed.

Time Complexity:
O(N)

where,
N = size of the array

Space Complexity:
O(1)

since the array is modified in-place without using any extra data structure.
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {

        // Stores the increments required for the current element
        int cnt = 0;

        // Stores the total number of operations
        int ans = 0;

        // Traverse the array
        for (int i = 0; i < nums.size() - 1; i++) {

            // Current pair is already strictly increasing
            if (nums[i] < nums[i + 1])
                continue;

            else {

                // Calculate the increments needed to make
                // nums[i + 1] greater than nums[i]
                cnt += nums[i] - nums[i + 1] + 1;

                // Update the current element after incrementing
                nums[i + 1] += cnt;

                // Add the operations to the final answer
                ans += cnt;

                // Reset for the next iteration
                cnt = 0;
            }
        }

        return ans;
    }
};