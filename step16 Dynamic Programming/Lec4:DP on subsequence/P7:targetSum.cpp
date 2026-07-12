/*
====================================================================
QUESTION
====================================================================

You are given an integer array 'nums' and an integer 'target'.

You have to assign either a '+' sign or a '-' sign before every
element of the array.

Return the total number of different expressions whose value becomes
equal to 'target'.

--------------------------------------------------------------------

Example:

nums = [1,1,1,1,1]

target = 3

Output:

5

Explanation:

There are five different ways to assign '+' and '-' signs
such that the final expression evaluates to 3.

====================================================================
INTUITION
====================================================================

For every element, we have only two choices.

1. Put a '+' sign before the current element.
2. Put a '-' sign before the current element.

Since every element must be assigned exactly one sign,
we process the array one element at a time.

--------------------------------------------------------------------

Suppose we are currently at

        nums[ind]

If we place a '+' sign,

then the remaining elements must contribute

        target + nums[ind]

If we place a '-' sign,

then the remaining elements must contribute

        target - nums[ind]

Therefore, every index branches into two recursive calls.

Hence,

                f(ind,target)

                     |
              ----------------
              |              |
            '+'             '-'
              |              |
 target+nums[ind]   target-nums[ind]

The total number of ways is simply

        Plus + Minus

--------------------------------------------------------------------

Base Case

When only one element remains (ind == 0),

there are three possibilities.

Case 1

nums[0] = 0

target = 0

Both

        +0

and

        -0

are valid expressions.

Hence,

return 2.

------------------------------------------------------------

Case 2

If

target == nums[0]

or

target == -nums[0]

Exactly one valid expression exists.

Return 1.

------------------------------------------------------------

Case 3

Otherwise,

no valid expression exists.

Return 0.

====================================================================
RECURSIVE RELATION
====================================================================

Ways

=

Plus

+

Minus

====================================================================
TIME COMPLEXITY
====================================================================

O(2^N)

Every element generates two recursive calls.

====================================================================
SPACE COMPLEXITY
====================================================================

O(N)

Auxiliary recursion stack.
*/

class Solution {
public:

    int f(int ind, vector<int>& nums, int n, int target){

        // Base Case
        if(ind == 0){

            // +0 and -0
            if(target == 0 && nums[0] == 0)
                return 2;

            // Either +nums[0] or -nums[0]
            if(target == nums[ind] || target == -nums[ind])
                return 1;

            // No valid expression
            return 0;
        }

        // Put '+' before current element
        int plus = f(ind - 1, nums, n, target + nums[ind]);

        // Put '-' before current element
        int minus = f(ind - 1, nums, n, target - nums[ind]);

        // Total number of ways
        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return f(nums.size() - 1, nums, nums.size(), target);
    }
};


/*
====================================================================
INTUITION
====================================================================

This problem can be converted into the

        Partition With Given Difference

problem.

------------------------------------------------------------

Suppose,

Sum of elements having '+' sign = S1

Sum of elements having '-' sign = S2

The final expression becomes

        S1 - S2 = target

Also,

every element belongs to exactly one of these two groups.

Therefore,

        S1 + S2 = TotalSum

Now we have two equations.

        S1 + S2 = TotalSum

        S1 - S2 = target

Subtract the second equation from the first.

        (S1 + S2) - (S1 - S2)

        = TotalSum - target

        2 × S2 = TotalSum - target

Therefore,

        S2 = (TotalSum - target) / 2

Hence,

instead of assigning '+' and '-' signs,

we only need to count

"How many subsets have sum equal to"

        (TotalSum - target) / 2

Once S2 is fixed,

S1 is automatically determined.

Therefore,

this problem becomes exactly

        Count Subsets With Sum K

which is the same reduction used in

        Partition With Given Difference.

------------------------------------------------------------

Impossible Cases

If

        TotalSum - target < 0

then the required subset sum becomes negative,

which is impossible.

Hence,

return 0.

------------------------------------------------------------

If

        (TotalSum - target)

is odd,

then

        (TotalSum - target) / 2

is not an integer.

Subset sums are always integers.

Hence,

return 0.

------------------------------------------------------------

Now simply solve

        Count Subsets With Sum

for

        target = (TotalSum - target) / 2

====================================================================
TIME COMPLEXITY
====================================================================

O(N × Target)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N × Target)

for DP table

+

O(N)

auxiliary recursion stack.
*/

class Solution {
public:

int countSubsequenceWithSumK(vector<int> &arr,int ind,int target,vector<vector<int>> &dp){
    if(ind==0){
        if(target==0 && arr[0]==0) return 2;
        if(target==0 || target==arr[ind]) return 1;
        return 0;
    }

    if(dp[ind][target]!=-1) return dp[ind][target];

    int pick=0;
    if(target>=arr[ind]) pick=countSubsequenceWithSumK(arr,ind-1,target-arr[ind],dp);
    int notPick=countSubsequenceWithSumK(arr,ind-1,target,dp);

    return dp[ind][target]=pick+notPick;
}

int findWays(vector<int> &arr,int n,int target){
    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

    return countSubsequenceWithSumK(arr,n-1,target,dp);
}

    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }

        if(total-target<0 || (total-target)%2==1) return 0;

        return findWays(nums,nums.size(),(total-target)/2);
    }
};