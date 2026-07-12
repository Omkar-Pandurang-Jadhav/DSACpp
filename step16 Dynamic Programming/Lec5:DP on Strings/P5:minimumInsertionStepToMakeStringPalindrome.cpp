/*
====================================================================
INTUITION
====================================================================

A palindrome reads the same from left to right
and right to left.

Instead of directly thinking about insertions,

first find the

Longest Palindromic Subsequence (LPS).

------------------------------------------------------------

Observation

The LPS is already a palindrome.

We do not need to insert anything for the characters
that are already part of the LPS.

Only the remaining characters need matching partners
to make the entire string a palindrome.

Therefore,

Minimum Insertions

=

Length of String

-

Length of Longest Palindromic Subsequence

------------------------------------------------------------

Now,

How do we find the LPS?

A palindrome remains the same when reversed.

So,

Longest Palindromic Subsequence

=

Longest Common Subsequence

between

Original String

and

Reversed String.

Hence,

1.

Reverse the string.

2.

Find the LCS of

Original String

and

Reversed String.

3.

Answer

=

n - LCS.

====================================================================
TIME COMPLEXITY
====================================================================

O(N²)

LCS using Memoization.

====================================================================
SPACE COMPLEXITY
====================================================================

O(N²)

for DP table

+

O(2N)

auxiliary recursion stack.
*/

class Solution {
public:

    int f(string &s1,string &s2,int n,int m,vector<vector<int>> &dp){

        if(n<0 || m<0)
            return 0;

        if(dp[n][m]!=-1)
            return dp[n][m];

        // Characters match
        if(s1[n]==s2[m])
            return dp[n][m]=1+f(s1,s2,n-1,m-1,dp);

        // Ignore one character
        return dp[n][m]=max(f(s1,s2,n-1,m,dp),f(s1,s2,n,m-1,dp));
    }

    int minInsertions(string s) {

        int n=s.size();

        string s2=s;

        reverse(s.begin(),s.end());

        string temp=s2;
        s2=s;
        s=temp;

        vector<vector<int>> dp(n,vector<int>(n,-1));

        // Length of Longest Palindromic Subsequence
        int m=f(s,s2,n-1,n-1,dp);

        // Minimum Insertions
        return n-m;
    }
};