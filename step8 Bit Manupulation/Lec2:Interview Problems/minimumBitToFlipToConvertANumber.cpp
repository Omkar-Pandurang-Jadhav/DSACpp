class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        // Step 1: XOR will give 1 at positions where bits are different
        // Example: start = 10 (1010), goal = 7 (0111)
        // start ^ goal = 1101 → we need to count number of 1s
        int n = start ^ goal;
        
        int cnt = 0;

        // Step 2: Brian Kernighan’s Algorithm
        // Each iteration removes the lowest set bit (1)
        // n = n & (n - 1)
        while (n != 0) {
            n = n & (n - 1);
            cnt++;
        }

        return cnt;
    }
};

// Time Complexity: O(k)
// Where k = number of set bits in (start ^ goal)
// In worst case, k ≤ 32 (for 32-bit integer)
// So effectively O(1) for fixed integer size.