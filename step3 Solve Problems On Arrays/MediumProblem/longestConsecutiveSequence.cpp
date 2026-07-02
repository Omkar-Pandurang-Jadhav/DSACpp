/*
Question:
Given an unsorted array of integers nums, return the length of the
longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3

Approach:
1. Handle the edge case where the array is empty.
2. Sort the given array so that consecutive numbers appear together.
3. Traverse the sorted array while maintaining the current consecutive
   sequence length.
4. If the current element is exactly one greater than the previous element,
   extend the current sequence.
5. If duplicate elements are encountered, ignore them.
6. Whenever the sequence breaks, update the maximum length found so far
   and restart the sequence count.
7. Return the maximum consecutive sequence length.

Time Complexity:
O(N log N)
because the array is sorted before traversal.

Space Complexity:
O(1)
excluding the space used by the sorting algorithm.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        // If the array is empty, no consecutive sequence exists
        if (n == 0) return 0;

        // Sort the array to bring consecutive elements together
        sort(nums.begin(), nums.end());

        // Stores the current consecutive sequence length
        int len = 1;

        // Stores the maximum consecutive sequence length
        int ans = -1;

        // Traverse the sorted array
        for (int i = 1; i < n; i++) {

            // Current element continues the consecutive sequence
            if (nums[i] - nums[i - 1] == 1) {
                len += 1;
            }

            // Ignore duplicate elements
            else if (nums[i] - nums[i - 1] == 0) {
                len += 0;
            }

            // Sequence is broken
            else {
                ans = max(ans, len);
                len = 1;
            }
        }

        // Update answer for the final sequence
        ans = max(ans, len);

        return ans;
    }
};