/*Given a binary array nums and an integer goal, return the number of 
non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
*/


/*
============================================================
NUMBER OF SUBARRAYS WITH SUM = GOAL (4 APPROACHES)
============================================================

PROBLEM:
Count number of subarrays with sum exactly equal to goal.
(nums contains only 0 and 1)

============================================================


------------------------------------------------------------
1️⃣ BRUTE FORCE (Nested Loops)
------------------------------------------------------------

APPROACH:
- Fix starting index i
- Expand subarray using j
- Keep running sum
- If sum == goal → count++
- If sum > goal → break (since only 0/1)

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2)

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

------------------------------------------------------------
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==goal) cnt++;
                else if(sum>goal) break;
            }
        }
        return cnt;
    }
};



/*
------------------------------------------------------------
2️⃣ PREFIX SUM + MAP
------------------------------------------------------------

APPROACH:
- Maintain prefix sum
- If preSum - goal exists → add its frequency
- Store prefix frequencies in map

------------------------------------------------------------

TIME COMPLEXITY:
O(n log n)

→ map operations

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

------------------------------------------------------------
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt=0;
        int l=0;
        int r=0;
        map<int,int> mpp;
        mpp[0]=1;
        int preSum=0;

        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            int remove=preSum-goal;
            cnt+=mpp[remove];
            mpp[preSum]+=1;
        }
        return cnt;
    }
};



/*
------------------------------------------------------------
3️⃣ PREFIX SUM + ARRAY (OPTIMIZED)
------------------------------------------------------------

APPROACH:
- Same as map version
- Use vector since prefix sum ≤ n (0/1 array)

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

------------------------------------------------------------
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt=0;
        int l=0;
        int r=0;
        vector<int> hash(nums.size()+1,0);
        hash[0]=1;
        int preSum=0;

        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            int remove=preSum-goal;
            if(remove>=0) cnt+=hash[remove];
            hash[preSum]+=1;
        }
        return cnt;
    }
};



/*
------------------------------------------------------------
4️⃣ SLIDING WINDOW (AT MOST TRICK ⭐)
------------------------------------------------------------

APPROACH:
- Count subarrays with sum ≤ goal
- Count subarrays with sum ≤ goal-1
- Subtract both:

    exact = atMost(goal) - atMost(goal-1)

------------------------------------------------------------

TIME COMPLEXITY:
O(2n) → O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

------------------------------------------------------------

KEY INSIGHT:
- Works because array contains only 0 and 1
- Sliding window works for non-negative arrays

------------------------------------------------------------
*/

class Solution {
public:
    int function(vector<int> &nums,int goal){
        if(goal<0) return 0;
        int cnt=0;
        int l=0;
        int r=0;
        int sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l+=1;
            }
            cnt+=r-l+1;
            r+=1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

       return function(nums,goal)-function(nums,goal-1);         
    }
};



/*
============================================================
DRY RUN (APPROACH 4) → nums = [1,0,1,0,1], goal = 2
============================================================

We compute:
ans = atMost(2) - atMost(1)

------------------------------------------------------------
👉 STEP 1: atMost(2)
------------------------------------------------------------

r=0 → sum=1 → cnt += 1 → total=1
r=1 → sum=1 → cnt += 2 → total=3
r=2 → sum=2 → cnt += 3 → total=6
r=3 → sum=2 → cnt += 4 → total=10
r=4 → sum=3 ❌

    shrink:
    remove nums[0]=1 → sum=2

    cnt += (4-1+1)=4 → total=14

👉 atMost(2) = 14

------------------------------------------------------------
👉 STEP 2: atMost(1)
------------------------------------------------------------

r=0 → sum=1 → cnt +=1 → total=1
r=1 → sum=1 → cnt +=2 → total=3
r=2 → sum=2 ❌

    shrink:
    remove nums[0]=1 → sum=1

    cnt += (2-1+1)=2 → total=5

r=3 → sum=1 → cnt +=3 → total=8
r=4 → sum=2 ❌

    shrink:
    remove nums[1]=0 → sum=2
    remove nums[2]=1 → sum=1

    cnt += (4-3+1)=2 → total=10

👉 atMost(1) = 10

------------------------------------------------------------
👉 FINAL ANSWER
------------------------------------------------------------

exact = 14 - 10 = 4

------------------------------------------------------------

VALID SUBARRAYS:
[1,0,1]
[0,1,0,1]
[1,0,1] (last 3)
[1,0,1] (first 3)

============================================================
*/