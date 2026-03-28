


class Solution {
public:
    int noOfJumps(vector<int> &nums,int jumps,int n,int ind){
        if(ind>=n-1) return jumps;
        int mini=INT_MAX;
        for(int i=1;i<=nums[ind];i++){
            mini=min(mini,noOfJumps(nums,jumps+1,n,ind+i));
        }
        return mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        int ans=noOfJumps(nums,0,n,0);
        return ans;
    }
};


// TC-O(N^N)
// we will modify it by using dp


// Optimal solution
class Solution {
public:
    int minJumps(vector<int>& arr) {
        /*
        Problem:
        --------
        Given an array `arr`, where each element represents max jump length 
        from that position, return minimum jumps to reach the end.

        Approach:
        ---------
        - Use a greedy approach:
          1. Maintain current range [l, r] which can be reached in current jumps.
          2. For all positions i in [l, r], calculate farthest = max(i + arr[i]).
          3. Update l = r + 1, r = farthest, increment jumps.
          4. Repeat until r >= n-1.
        */

        int n = arr.size();
        if(n <= 1) return 0;  // Already at the end

        int l = 0, r = 0;  // Current range reachable in current jumps
        int jumps = 0;

        while(r < n - 1){
            int farthest = r;  // Track farthest we can reach in next jump
            for(int i = l; i <= r; i++){
                farthest = max(farthest, i + arr[i]);
            }

            // If we can't move further → unreachable
            if(farthest == r) return -1;

            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};
