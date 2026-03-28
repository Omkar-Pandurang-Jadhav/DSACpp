/*Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter 
takes 1 unit 
of time to paint 1 unit length of a board.

Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a
 contiguous sequence of boards (no skipping or splitting allowed).

Examples:

Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The optimal allocation of boards among 3 painters is - 
Painter 1 → [5, 10] → time = 15
Painter 2 → [30] → time = 30
Painter 3 → [20, 15] → time = 35
Job will be done when all painters finish i.e. at time = max(15, 30, 35) = 35

Input: arr[] = [10, 20, 30, 40], k = 2
Output: 60
Explanation: A valid optimal partition is - 
Painter 1 → [10, 20, 30] → time = 60
Painter 2 → [40] → time = 40
Job will be complete at time = max(60, 40) = 60

Input: arr[] = [100, 200, 300, 400], k = 1
Output: 1000
Explanation: There is only one painter, so the painter must paint all boards sequentially. The total time taken will be the sum of all board 
lengths, i.e., 100 + 200 + 300 + 400 = 1000.*/


class Solution {
  public:
    // Helper: returns number of partitions needed
    // if we do not allow any partition sum > mid
    int partitionElement(vector<int> arr, int mid) {
        int cnt = 1;   // at least 1 partition
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] + sum <= mid) {
                // add this element to current partition
                sum += arr[i];
            } else {
                // start new partition
                sum = arr[i];
                cnt++;
            }
        }
        return cnt; // how many partitions were needed
    }

    int minTime(vector<int>& arr, int k) {
        // Search space:
        // low = max element (minimum possible max load)
        // high = sum of all elements (maximum possible load)
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // if more partitions needed than k → increase limit
            if (partitionElement(arr, mid) > k) {
                low = mid + 1;
            } 
            // else try smaller limit
            else {
                high = mid - 1;
            }
        }
        return low; // minimum possible max load
    }
};

/*
-----------------------------------
Approach (Binary Search on Answer):
-----------------------------------
We want to partition the array into k subarrays 
such that the maximum sum among them is minimized.

1. Define search space:
   - low = max(arr)  (no partition can be less than largest element)
   - high = sum(arr) (one partition takes everything)
2. For each mid = (low+high)/2:
   - Check how many partitions are required if max allowed sum = mid.
   - If more than k partitions needed → mid too small → increase low.
   - Else mid is feasible → try smaller value (decrease high).
3. Return low as the minimum possible "largest partition sum".

-----------------------------------
Dry Run Example:
-----------------------------------
arr = [10, 20, 30, 40], k = 2

low = max(10,20,30,40) = 40
high = sum = 100

mid=70 → partition = [10,20,30] + [40] → 2 partitions ✅ → reduce high=69
mid=54 → partition = [10,20] + [30] + [40] → 3 partitions ❌ → increase low=55
mid=62 → partition = [10,20,30] + [40] → 2 partitions ✅ → reduce high=61
mid=58 → partition = [10,20] + [30] + [40] → 3 partitions ❌ → increase low=59
mid=60 → partition = [10,20] + [30] + [40] → 3 partitions ❌ → increase low=61
mid=61 → partition = [10,20] + [30] + [40] → 3 partitions ❌ → increase low=62

Loop ends → answer = 62

So, minimum possible max load = 60? No → Actually 60 failed, so it's 61? 
Check carefully: Final answer = low = 60? Let's double-check:

Final low=62, high=61 → exit → answer=62 ✅

-----------------------------------
Time Complexity:
-----------------------------------
- Each check (partitionElement) = O(n)
- Binary search iterations = O(log(sum(arr) - max(arr)))
=> Total = O(n log(sum(arr)))

Space Complexity: O(1)

-----------------------------------
*/
