class Solution {
  public:
    /*
    Approach:
    - We need to find integer x such that x^n = m.
    - Use binary search on [1, m].
    - For each mid, compute mid^n using fast exponentiation.
    - If mid^n == m → found root.
    - If mid^n < m → search right.
    - If mid^n > m → search left.
    
    Time Complexity:
    - O(log n * log m)
      (binary exponentiation is O(log n), binary search is O(log m))
    Space Complexity:
    - O(1)
    */

    // fast exponentiation (binary exponentiation)
    long long powFunction(int n, int mid, int m) {
        long long ans = 1;
        long long base = mid;

        while (n > 0) {
            if (n % 2 == 1) {
                ans *= base;
                if (ans > m) return ans; // early stop (overflow guard)
                n--;
            } else {
                base *= base;
                if (base > m) return base; // guard
                n /= 2;
            }
        }
        return ans;
    }

    int nthRoot(int n, int m) {
        int low = 1, high = m, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long power = powFunction(n, mid, m); // compute mid^n

            if (power == m) {
                ans = mid;  // found exact root
                break;
            } 
            else if (power < m) {
                low = mid + 1; // need bigger mid
            } 
            else {
                high = mid - 1; // too big
            }
        }
        return ans;
    }
};
