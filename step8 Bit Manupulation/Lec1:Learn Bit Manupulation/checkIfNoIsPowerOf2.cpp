class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        if(((long long)n&((long long)n-1))==0) return true;
        return false;
    }
};