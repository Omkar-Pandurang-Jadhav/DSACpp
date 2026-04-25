
/*
Given an array of integers nums and an integer k. A continuous subarray is called
 nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/


/*
============================================================
COUNT NUMBER OF NICE SUBARRAYS (3 APPROACHES)
============================================================

PROBLEM:
Count subarrays with exactly k odd numbers.

============================================================


------------------------------------------------------------
1️⃣ BRUTE FORCE (Nested Loops)
------------------------------------------------------------

APPROACH:
- Fix starting index i
- Expand j
- Count odd numbers
- If cntOdd == k → increment answer
- If cntOdd > k → break

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2)

→ Outer loop: n
→ Inner loop: up to n

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

------------------------------------------------------------
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int cntOdd=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==1) cntOdd+=1;
                if(cntOdd==k) cnt+=1;
                else if(cntOdd>k) break;
            }
        }
        return cnt;
    }
};



/*
------------------------------------------------------------
2️⃣ SLIDING WINDOW (AT MOST TRICK)
------------------------------------------------------------

APPROACH:
- Count subarrays with at most k odd numbers
- Count subarrays with at most (k-1)
- Subtract:
    exact = atMost(k) - atMost(k-1)

------------------------------------------------------------

TIME COMPLEXITY:
O(2n) → O(n)

→ r moves n times
→ l moves at most n times

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

------------------------------------------------------------
*/

class Solution {
public:
    int function(vector<int> nums,int k){
        int cnt=0;
        int l=0;
        int r=0;
        int cntOdd=0;
        while(r<nums.size()){
            if(nums[r]%2==1) cntOdd+=1;
            while(cntOdd>k){
                if(nums[l]%2==1) cntOdd-=1;
                l+=1;
            }
            cnt+=r-l+1;
            r+=1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return function(nums,k)-function(nums,k-1);
    }
};



/*
------------------------------------------------------------
3️⃣ SLIDING WINDOW (0/1 TRANSFORMATION)
------------------------------------------------------------

APPROACH:
- Convert array:
    odd → 1
    even → 0
- Now problem becomes:
    count subarrays with sum = k
- Use same atMost trick

------------------------------------------------------------

TIME COMPLEXITY:
O(2n) → O(n)

→ Conversion: O(n)
→ Sliding window: O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

------------------------------------------------------------
*/

class Solution {
public:
    int function(vector<int> nums,int k){
        if(k<0) return 0;
        int cnt=0;
        int l=0;
        int r=0;
        int sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>k){
                sum-=nums[l];
                l+=1;
            }
            cnt+=r-l+1;
            r+=1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        return function(nums,k)-function(nums,k-1);
    }
};



/*
============================================================
FINAL COMPARISON
============================================================

| Approach            | Time Complexity | Space |
|---------------------|----------------|-------|
| Brute Force         | O(n^2) ❌      | O(1)  |
| Sliding Window Odd  | O(2n) ⭐       | O(1)  |
| Sliding Window 0/1  | O(2n) ⭐       | O(1)  |

============================================================

KEY INSIGHT:
- Exactly k = atMost(k) - atMost(k-1)
- Works because values are non-negative
- Transforming to 0/1 simplifies logic

============================================================
*/