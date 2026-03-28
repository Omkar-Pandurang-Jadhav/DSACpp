class Solution {
  public:
    /*
    -------------------------------------------
    Approach:
    1. We want to find floor(sqrt(n)), i.e., the largest integer x 
       such that x*x <= n.
    2. Apply Binary Search on the range [1, n]:
       - mid = (low + high)/2
       - If mid*mid <= n → this mid is a valid candidate, 
         so store it in 'ans' and move right (low = mid+1) to try bigger values.
       - Else (mid*mid > n) → mid is too big, move left (high = mid-1).
    3. At the end, 'ans' will store the floor of sqrt(n).

    -------------------------------------------
    Time Complexity:
    - O(log n) (binary search on range [1, n])

    Space Complexity:
    - O(1) extra space
    -------------------------------------------
    */

    int floorSqrt(int n) {
        int low = 1;        // smallest candidate
        int high = n;       // largest candidate
        int ans = 1;        // stores best possible answer

        // Binary Search loop
        while (low <= high) {
            int mid = low + (high - low) / 2;   // middle element

            if ((long long)mid * mid <= n) {   // safe check to avoid overflow
                ans = mid;     // mid is valid → store as candidate
                low = mid + 1; // try to find bigger square root
            }
            else {
                high = mid - 1; // mid*mid > n → move left
            }
        }
        return ans; // floor(sqrt(n))
    }
};
