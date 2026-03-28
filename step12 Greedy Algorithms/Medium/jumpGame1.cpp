/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

 */

 class Solution {
public:
    /*
    Question:
    ----------
    You are given an integer array nums. 
    - You are initially positioned at the first index.
    - Each element represents the maximum jump length from that position.
    - Return true if you can reach the last index, else false.

    Example:
    Input: nums = [2,3,1,1,4]
    Output: true
    Explanation: 
        Jump from index 0 to 1 (max 2 steps)
        Then jump from index 1 to 4 (max 3 steps)

    Approach:
    -----------
    1. Use a **greedy approach**:
       - Track the farthest reachable index (`maxJump`) at every step.
       - Iterate through the array:
         - If the current index is reachable (`maxJump >= i`), update `maxJump` as the maximum of current `maxJump` and `i + nums[i]`.
         - If at any point the current index `i` is beyond `maxJump`, return false (we can't reach this position).
       - If loop completes, it means last index is reachable, so return true.

    Time Complexity:
    ----------------
    O(N)  — as we traverse the array once.

    Space Complexity:
    -----------------
    O(1)  — no extra space used apart from variables.
    */

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxJump = 0;  // maximum index reachable at any point
        
        for(int i = 0; i < n; i++){
            if(maxJump >= i){
                // Update maxJump: max of current maxJump and current position's maximum jump
                maxJump = max(maxJump, i + nums[i]);
            }
            else {
                // If current index is not reachable
                return false;
            }
        }
        
        // If loop completes, last index is reachable
        return true;
    }
};
