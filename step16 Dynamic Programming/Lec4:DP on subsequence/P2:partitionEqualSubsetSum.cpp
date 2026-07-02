/*
===============================================================
QUESTION
===============================================================

Given an integer array nums, return true if you can partition
the array into two subsets such that the sum of elements in
both subsets is equal.

Return true if such a partition exists, otherwise return false.

Example 1:
Input:
nums = [1,5,11,5]

Output:
true

Explanation:
Subset 1 = [1,5,5]
Subset 2 = [11]

Both have sum = 11.

---------------------------------------------------------------

Example 2:
Input:
nums = [1,2,3,5]

Output:
false

===============================================================
INTUITION
===============================================================

Suppose the total sum of the array is

        S

If the array can be divided into two equal subsets,

then

Subset1 + Subset2 = S

Since both subset sums are equal,

Subset1 = Subset2

Therefore,

2 × Subset1 = S

Hence,

Subset1 = S / 2

This means the original problem becomes:

"Can we find a subset whose sum is S/2?"

If total sum is odd,

it can never be divided equally.

Hence,

if(sum % 2 != 0)

return false.

Otherwise,

Target = sum / 2

Now the problem becomes the standard
Subset Sum Equal to K problem.

For every element we have two choices.

1. Pick it.
2. Do not pick it.

This gives the recursion.

===============================================================
1. RECURSION
===============================================================

Approach:

For every index,

Try two possibilities:

1. Pick current element.
2. Do not pick current element.

If either returns true,

a valid subset exists.

Time Complexity:
O(2^N)

Space Complexity:
O(N)

(Recursion stack)

---------------------------------------------------------------
*/

class Solution {
public:

    bool f(int ind, vector<int> &nums, int k){

        if(k==0) return true;

        if(ind==0) return nums[0]==k;

        bool notPick=f(ind-1,nums,k);

        bool pick=false;

        if(k>=nums[ind])
            pick=f(ind-1,nums,k-nums[ind]);

        return (pick || notPick);
    }

    bool canPartition(vector<int>& nums) {

        int sum=0;

        int n=nums.size();

        for(int i=0;i<n;i++)
            sum+=nums[i];

        if(sum%2==1)
            return false;

        int target=sum/2;

        return f(n-1,nums,target);
    }
};



/*
===============================================================
2. MEMOIZATION
===============================================================

Intuition:

The recursive solution solves the same state repeatedly.

State:

dp[ind][target]

=

Can we form target
using elements from index 0 to ind ?

Whenever a state is already solved,

return the stored answer.

Time Complexity:
O(N × K)

Space Complexity:
O(N × K)

for DP table

+

O(N)

auxiliary recursion stack.
---------------------------------------------------------------
*/

class Solution {
public:

    bool f(int ind,
           vector<int> &nums,
           int k,
           vector<vector<int>> &dp){

        if(k==0)
            return true;

        if(ind==0)
            return nums[0]==k;

        if(dp[ind][k]!=-1)
            return dp[ind][k];

        bool notPick=f(ind-1,nums,k,dp);

        bool pick=false;

        if(k>=nums[ind])
            pick=f(ind-1,nums,k-nums[ind],dp);

        return dp[ind][k]=(pick || notPick);
    }

    bool canPartition(vector<int>& nums) {

        int sum=0;

        int n=nums.size();

        for(int i=0;i<n;i++)
            sum+=nums[i];

        if(sum%2==1)
            return false;

        int target=sum/2;

        vector<vector<int>> dp(
            n,
            vector<int>(target+1,-1)
        );

        return f(n-1,nums,target,dp);
    }
};



/*
===============================================================
3. TABULATION
===============================================================

Intuition:

Instead of solving recursively,

store every state directly inside a DP table.

State:

dp[ind][target]

=

Can we form target
using elements from 0 to ind ?

Transition:

Pick

or

Not Pick

The answer for every row depends only on the row above.

Time Complexity:
O(N × K)

Space Complexity:
O(N × K)

No recursion stack is required because recursion
has been completely removed.

---------------------------------------------------------------
*/

class Solution {
public:

    bool canPartition(vector<int>& nums) {

        int sum=0;

        int n=nums.size();

        for(int i=0;i<n;i++)
            sum+=nums[i];

        if(sum%2==1)
            return false;

        int k=sum/2;

        vector<vector<bool>> dp(
            n,
            vector<bool>(k+1,false)
        );

        for(int i=0;i<n;i++)
            dp[i][0]=true;

        if(nums[0]<=k)
            dp[0][nums[0]]=true;

        for(int ind=1;ind<n;ind++){

            for(int target=1;target<=k;target++){

                bool notPick=dp[ind-1][target];

                bool pick=false;

                if(target>=nums[ind])
                    pick=dp[ind-1][target-nums[ind]];

                dp[ind][target]=(pick || notPick);
            }
        }

        return dp[n-1][k];
    }
};



/*
===============================================================
4. SPACE OPTIMIZATION
===============================================================

Intuition:

Observe the transition carefully.

dp[ind][target]

depends only on

dp[ind-1][...]

Therefore,

keeping the entire DP table is unnecessary.

Replace

dp[ind-1][...]

by

prev[...]

Replace

dp[ind][...]

by

cur[...]

After finishing one row,

simply do

prev = cur

This reduces the space from

O(N × K)

to

O(K).

Time Complexity:
O(N × K)

Space Complexity:
O(K)

---------------------------------------------------------------
*/

class Solution {
public:

    bool canPartition(vector<int>& nums) {

        int sum=0;

        int n=nums.size();

        for(int i=0;i<n;i++)
            sum+=nums[i];

        if(sum%2==1)
            return false;

        int k=sum/2;

        vector<bool> prev(k+1,false);

        vector<bool> cur(k+1,false);

        prev[0]=true;

        cur[0]=true;

        if(nums[0]<=k)
            prev[nums[0]]=true;

        for(int ind=1;ind<n;ind++){

            for(int target=1;target<=k;target++){

                bool notPick=prev[target];

                bool pick=false;

                if(target>=nums[ind])
                    pick=prev[target-nums[ind]];

                cur[target]=(pick || notPick);
            }

            prev=cur;
        }

        return prev[k];
    }
};