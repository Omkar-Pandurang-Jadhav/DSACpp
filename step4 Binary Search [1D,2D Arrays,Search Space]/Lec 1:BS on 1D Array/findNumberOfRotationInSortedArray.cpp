/*

Given an increasing sorted rotated array arr[] of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr[] = [2, 4, 6, 9], if we rotate it by 2 times it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]

Examples:

Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 
times to the right.

Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The given array is not rotated.
*/


class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Case 1: Only one element left
            if (low == high) return low;

            // Case 2: If the range [low..high] is already sorted,
            // then arr[low] is the smallest
            if (arr[low] <= arr[mid] && arr[mid] <= arr[high]) 
                return low;

            // Case 3: Left half is sorted, so min must be in right half
            if (arr[low] <= arr[mid]) {
                low = mid + 1;
            }
            // Case 4: Right half is sorted, so min lies in left half (including mid)
            else {
                high = mid;
            }
        }
        return 0; // fallback (array not rotated)
    }
};

/*
----------------------------------------------------
Approach:
- Rotation count = index of the smallest element.
- Use binary search to find pivot point.
- Check if current range is sorted → return low.
- Otherwise, discard the sorted half and search in the unsorted half.
- Continue until we narrow down to one element.

Time Complexity: O(log n)
Space Complexity: O(1)
----------------------------------------------------
*/
