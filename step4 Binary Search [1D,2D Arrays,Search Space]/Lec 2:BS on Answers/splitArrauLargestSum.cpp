/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

 

*/


class Solution {
public:
    // Greedy check function:
    // Given a maximum allowed subarray sum = mid,
    // return how many subarrays (splits) are needed
    int returnNoOfSplit(vector<int> &arr,int mid,int k){
        int cnt=1;   // at least one subarray
        int sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i] <= mid){
                sum += arr[i];   // add element if it fits
            }
            else{
                // start a new subarray
                sum = arr[i];
                cnt++;
            }
        }
        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        // Search space:
        // low = max element (smallest possible max subarray sum)
        // high = sum of all elements (largest possible max subarray sum)
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        // Binary search on the "answer" (minimized largest subarray sum)
        while(low <= high){
            int mid = low + (high-low)/2;

            // Count number of subarrays if largest allowed sum = mid
            if(returnNoOfSplit(nums, mid, k) > k){
                // Too many splits → capacity too small
                low = mid + 1;
            }
            else{
                // Valid split, try smaller maximum
                high = mid - 1;
            }
        }

        return low; // minimum largest subarray sum
    }
};

/*
-----------------------------------------------------
Approach:
1. Use binary search on the answer range:
   - Lower bound = max element (since one subarray must hold it).
   - Upper bound = sum of array (everything in one subarray).
2. For each candidate value 'mid', check with greedy:
   - Traverse array, accumulate sum until it exceeds 'mid'.
   - Start a new subarray if exceeded.
   - Count subarrays formed.
3. If subarrays > k → need larger capacity (increase low).
   Else → try smaller capacity (decrease high).
4. Return the minimum 'low' that satisfies condition.

-----------------------------------------------------
Time Complexity:
- Each check = O(n) (linear scan of array).
- Binary search range ≈ sum(nums) - max(nums),
  so ≈ O(log(sum(nums))).
- Overall = O(n * log(sum(nums))).

Space Complexity:
- O(1) extra space (only variables).

-----------------------------------------------------
Optimality:
- Cannot be improved below O(n log(sum)) because:
  - At least O(n) work needed to check feasibility.
  - At least O(log(sum)) binary search steps required.
- Same optimal approach as "Book Allocation" / "Ship Capacity".
-----------------------------------------------------
*/
