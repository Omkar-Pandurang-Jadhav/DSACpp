/*You are given an array with unique elements of stalls[], which denote the positions of stalls. 
You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls
 to k cows such that the minimum distance between any two of them is the maximum possible.

Examples:

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows in this case is 3, which is the largest among all possible ways.

Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows in this case is 4, which is the largest among all possible ways.

Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows in this case is 1, which is the largest among all possible ways.

*/

class Solution {
  public:
    // Helper function: check if we can place 'k' cows
    // such that minimum distance between any two cows >= mid
    bool canWePlace(vector<int> arr, int mid, int k) {
        int cntCow = 1;          // place first cow at arr[0]
        int n = arr.size();
        int last = arr[0];       // last placed cow position

        for (int i = 1; i < n; i++) {
            if (arr[i] - last >= mid) {  
                // we can place another cow here
                last = arr[i];
                cntCow++;
            }
        }
        return cntCow >= k; // if we can place at least k cows
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end()); // sort stalls positions
        int n = stalls.size();

        int low = 1;                          // minimum possible distance
        int high = stalls[n-1] - stalls[0];   // maximum possible distance

        // Binary search on the answer (minimum distance)
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canWePlace(stalls, mid, k)) {
                // if we can place cows with >= mid distance, try bigger distance
                low = mid + 1;
            } else {
                // otherwise, reduce distance
                high = mid - 1;
            }
        }
        return high; // maximum minimum distance achievable
    }
};

/*
-----------------------------------
Approach (Binary Search on Answer):
-----------------------------------
1. We need to maximize the minimum distance between any two cows.
2. Sort stall positions.
3. Define search space:
     - low = 1  (minimum possible distance between cows)
     - high = stalls[n-1] - stalls[0]  (maximum possible distance if cows at ends)
4. For each mid = (low+high)/2, check if we can place all cows:
   - Greedily place the first cow at stalls[0].
   - Place the next cow at the first stall >= lastPlaced + mid.
   - Count how many cows placed.
   - If we can place >= k cows, it means mid is possible → try bigger distance.
   - Else reduce distance.
5. At the end, 'high' will be the largest minimum distance possible.

-----------------------------------
Dry Run Example:
-----------------------------------
stalls = [1, 2, 4, 8, 9], k = 3

low=1, high=8
mid=4 → can place at 1, 8 (only 2 cows) ❌ → reduce high=3
mid=2 → can place at 1, 4, 8 (3 cows) ✅ → increase low=3
mid=3 → can place at 1, 4, 8 (3 cows) ✅ → increase low=4

Loop ends → answer = high = 3

-----------------------------------
Time Complexity:
-----------------------------------
- Sorting: O(n log n)
- Binary search iterations: O(log(maxDistance)) ≈ O(log(10^9))
- Each feasibility check: O(n)
=> Total: O(n log n + n log(maxDistance))

Space Complexity: O(1) 
-----------------------------------
*/
