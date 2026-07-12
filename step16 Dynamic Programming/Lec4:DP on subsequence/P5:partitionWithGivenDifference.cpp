/*
====================================================================
QUESTION
====================================================================

Given an array ARR and an integer D, partition the array into two
subsets S1 and S2 such that

        S1 >= S2

and

        S1 - S2 = D

Return the number of such partitions.

Since the answer can be very large, return it modulo

        10^9 + 7.

====================================================================
INTUITION
====================================================================

Suppose,

Sum of first subset = S1

Sum of second subset = S2

The total sum of the array is

        Total = S1 + S2

We are also given

        S1 - S2 = D

Now we have two equations.

        S1 + S2 = Total

        S1 - S2 = D

Subtract the second equation from the first.

        (S1 + S2) - (S1 - S2)

        = Total - D

        2 × S2 = Total - D

Therefore,

        S2 = (Total - D) / 2

Hence, instead of finding two subsets,

we only need to count the number of subsets whose sum is

        (Total - D) / 2

because once S2 is fixed,

S1 is automatically fixed.

Therefore,

this problem becomes exactly the

        Count Subsets With Sum K

problem.

------------------------------------------------------------

Impossible Cases

If

        Total - D < 0

then S2 becomes negative,

which is impossible.

Hence,

return 0.

------------------------------------------------------------

If

        (Total - D)

is odd,

then

        (Total - D) / 2

is not an integer.

Subset sums are always integers.

Hence,

return 0.

------------------------------------------------------------

Now simply solve

Count Subsets With Sum

for

        target = (Total - D) / 2

====================================================================
Time Complexity
====================================================================

O(N × Target)

====================================================================
Space Complexity
====================================================================

O(N × Target)

for DP table

+

O(N)

auxiliary recursion stack.
*/

#include <bits/stdc++.h> 
const int mod=1e9+7;
int countSubsequences(int ind,vector<int>& arr,int k,vector<vector<int>> &dp){
	if(ind == 0){
        if(k == 0 && arr[0] == 0) return 2;
        if(k == 0 || arr[0] == k) return 1;
        return 0;
    }

	if(dp[ind][k]!=-1){
		return dp[ind][k];
	}

	int pick=0;
	if(k>=arr[ind]) pick=countSubsequences(ind-1,arr,k-arr[ind],dp);
	int notPick=countSubsequences(ind-1,arr,k,dp);

	return dp[ind][k]=(pick+notPick)%mod;
}

int findWays(vector<int>& arr, int k){
	int n=arr.size();
	vector<vector<int>> dp(n+1,vector<int>(k+1,-1));

	return countSubsequences(n-1,arr,k,dp);
}
int countPartitions(int n, int d, vector<int> &arr) {
    int total=0;

    for(int i=0;i<n;i++){
        total+=arr[i];
    }

    if(total-d<0 || (total-d)%2==1) return 0;
    return findWays(arr,(total-d)/2);
}

