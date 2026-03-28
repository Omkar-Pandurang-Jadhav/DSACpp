class Solution {
public:
    
    // Time Complexity: O(N)
    // We iterate from L to R → (R - L + 1) times
    
    // Space Complexity: O(1)
    // Only one variable used
    
    int xorRange(int L, int R) {
        int result = 0;
        
        for(int i = L; i <= R; i++) {
            result ^= i;
        }
        
        return result;
    }
};

class Solution {
public:
    
    // Helper function: XOR from 1 to n
    int xorUptoN(int n) {
        
        if(n % 4 == 0) return n;
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n + 1;
        return 0;  // n % 4 == 3
    }
    
    /*
    Time Complexity: O(1)
    Only constant operations.
    
    Space Complexity: O(1)
    No extra space used.
    */
    
    int xorRange(int L, int R) {
        return xorUptoN(R) ^ xorUptoN(L - 1);
    }
};