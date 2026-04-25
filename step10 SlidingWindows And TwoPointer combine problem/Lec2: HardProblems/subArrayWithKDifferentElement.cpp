/*
Given an integer array nums and an integer k, return the number of good subarrays 
of nums.

A good array is an array where the number of different integers in that array is 
exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: 
[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: 
[1,2,1,3], [2,1,3], [1,3,4].*/


/*
============================================================
SUBARRAYS WITH EXACTLY K DISTINCT INTEGERS (2 APPROACHES)
============================================================

PROBLEM:
Count subarrays having exactly k distinct integers.

============================================================


------------------------------------------------------------
1️⃣ BRUTE FORCE (MAP + NESTED LOOPS)
------------------------------------------------------------

APPROACH:
- Fix starting index i
- Expand j
- Use map to track frequencies
- If distinct == k → count++
- If distinct > k → break

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2 * log k)

→ Outer loop: n
→ Inner loop: n
→ map ops: log k

------------------------------------------------------------

SPACE COMPLEXITY:
O(k)

------------------------------------------------------------
*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int cnt=0;
        
        for(int i=0;i<nums.size();i++){
            map<int,int> mpp;
            for(int j=i;j<nums.size();j++){
                mpp[nums[j]]+=1;
                if(mpp.size()==k) cnt+=1;
                else if(mpp.size()>k) break;
            }
        }
        return cnt;
    }
};



/*
------------------------------------------------------------
2️⃣ SLIDING WINDOW (AT MOST TRICK ⭐)
------------------------------------------------------------

APPROACH:
- Count subarrays with at most k distinct
- Count subarrays with at most (k-1)
- Subtract:

    exact = atMost(k) - atMost(k-1)

------------------------------------------------------------

TIME COMPLEXITY:
O(2n * log k)

→ r moves n times
→ l moves at most n times
→ map ops: log k

------------------------------------------------------------

SPACE COMPLEXITY:
O(k)

------------------------------------------------------------

KEY INSIGHT:
- exactly k = atMost(k) - atMost(k-1)
------------------------------------------------------------
*/

class Solution {
public:

    int function(vector<int> nums,int k){
        if(k<0) return 0;

        int l=0;
        int r=0;
        int cnt=0;
        map<int,int> mpp;

        while(r<nums.size()){

            mpp[nums[r]]+=1;

            while(mpp.size()>k){
                mpp[nums[l]]-=1;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l+=1;
            }

            cnt+=r-l+1;

            r+=1;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return function(nums,k)-function(nums,k-1);
    }
};



/*
============================================================
FINAL COMPARISON
============================================================

| Approach        | Time Complexity      | Space |
|----------------|---------------------|-------|
| Brute Force    | O(n^2 log k) ❌     | O(k)  |
| Sliding Window | O(2n log k) ⭐      | O(k)  |

============================================================


============================================================
❓ CAN WE OPTIMIZE FURTHER?
============================================================

👉 YES (only constant improvement, not asymptotic)

Instead of map → use array / unordered_map

------------------------------------------------------------

🔹 If nums values are small (like ≤ 10^5):

Use:
vector<int> freq(maxVal+1)

TIME:
O(2n)

SPACE:
O(maxVal)

------------------------------------------------------------

🔹 If values are large:

Use unordered_map:
→ average O(1) operations

TIME:
O(2n) average

SPACE:
O(k)

------------------------------------------------------------

❗ BUT IMPORTANT:

👉 You CANNOT do better than O(n) time  
Because:
- You must visit each element at least once

------------------------------------------------------------

💯 FINAL VERDICT:

| Optimization Level | Status |
|-------------------|--------|
| Current (map)     | ✅ Optimal asymptotically |
| Using array       | ⚡ Faster constant |
| Using unordered_map | ⚡ Average O(n) |
| Better than O(n)? | ❌ Impossible |

============================================================
*/