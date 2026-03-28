class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // Time Complexity: O(n)
        // We traverse the array once.
        // XOR operation inside loop takes O(1).
        // So total time = O(n).

        // Space Complexity: O(1)
        // We are using only one extra variable (sum),
        // no extra data structure is used.

        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum = sum ^ nums[i];   // XOR cancels duplicate elements
        }

        return sum;
    }
};