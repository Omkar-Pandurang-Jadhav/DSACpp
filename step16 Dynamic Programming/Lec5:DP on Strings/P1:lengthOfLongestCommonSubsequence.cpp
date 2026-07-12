/*
Given two strings text1 and text2, return the length of their longest common
subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with 
some characters (can be none) deleted without changing the relative order of the 
remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/

// Recursion

/*
====================================================================
INTUITION
====================================================================

This problem is solved by comparing the last characters of both strings.

Suppose

s1 = "abcde"
s2 = "ace"

We start from the last characters.

------------------------------------------------------------

Case 1 : Characters Match

Suppose

s1[n] == s2[m]

Since both characters are equal,

they must be a part of the LCS.

So,

1 is added to the answer and we continue searching
for the remaining characters.

LCS

=

1 + LCS(n-1,m-1)

------------------------------------------------------------

Case 2 : Characters Do Not Match

Suppose

s1[n] != s2[m]

Both characters cannot be included together.

So we have two choices.

1.

Ignore current character of s1

LCS(n-1,m)

2.

Ignore current character of s2

LCS(n,m-1)

Take the maximum of both choices.

------------------------------------------------------------

Base Case

If either string becomes empty,

there is no common subsequence.

Hence,

return 0.

====================================================================
TIME COMPLEXITY
====================================================================

O(2^(N+M))

====================================================================
SPACE COMPLEXITY
====================================================================

O(N+M)

Auxiliary recursion stack.
*/

class Solution {
public:

    int f(string &s1,string &s2,int n,int m){

        if(n<0 || m<0)
            return 0;

        if(s1[n]==s2[m])
            return 1+f(s1,s2,n-1,m-1);

        return max(f(s1,s2,n-1,m),f(s1,s2,n,m-1));
    }

    int longestCommonSubsequence(string text1, string text2) {

        int n=text1.size();
        int m=text2.size();

        return f(text1,text2,n-1,m-1);
    }
};




// Memoization
/*
====================================================================
INTUITION
====================================================================

The recursive state

dp[n][m]

represents

Length of LCS considering

s1[0...n]

and

s2[0...m].

Many recursive calls repeat the same state.

Store every computed answer in the DP table
to avoid recomputation.

====================================================================
TIME COMPLEXITY
====================================================================

O(N*M)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N*M)

for DP table

+

O(N+M)

auxiliary recursion stack.
*/

class Solution {
public:

    int f(string &s1,string &s2,int n,int m,vector<vector<int>> &dp){

        if(n<0 || m<0)
            return 0;

        if(dp[n][m]!=-1)
            return dp[n][m];

        if(s1[n]==s2[m])
            return dp[n][m]=1+f(s1,s2,n-1,m-1,dp);

        return dp[n][m]=max(f(s1,s2,n-1,m,dp),f(s1,s2,n,m-1,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {

        int n=text1.size();
        int m=text2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return f(text1,text2,n-1,m-1,dp);
    }
};


// Tabulation

/*
====================================================================
INTUITION
====================================================================

Memoization uses

n<0

or

m<0

as the base case.

Negative indices cannot be represented in a DP table.

Therefore,

we perform a Right Shift of Index.

------------------------------------------------------------

Original Index

-1   0   1   2   3

becomes

0   1   2   3   4

------------------------------------------------------------

Meaning

dp[i][j]

represents

LCS of

text1[0...i-1]

and

text2[0...j-1].

------------------------------------------------------------

Base Case

When either string length is zero,

LCS is zero.

Therefore,

First Row = 0

First Column = 0

------------------------------------------------------------

Transition

If

text1[i-1]==text2[j-1]

Current characters match.

Take them.

dp[i][j]

=

1+dp[i-1][j-1]

------------------------------------------------------------

Otherwise,

either ignore current character of text1

or

ignore current character of text2.

dp[i][j]

=

max(dp[i-1][j],dp[i][j-1])

====================================================================
TIME COMPLEXITY
====================================================================

O(N*M)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N*M)
*/

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {

        int n=text1.size();
        int m=text2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        // Base Cases
        for(int i=0;i<=n;i++)
            dp[i][0]=0;

        for(int j=0;j<=m;j++)
            dp[0][j]=0;

        // Fill DP Table
        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];

                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};


// Space Optimization

/*
====================================================================
INTUITION
====================================================================

From the tabulation solution,

observe that

dp[i][j]

depends only on

1.

dp[i-1][j]

2.

dp[i-1][j-1]

3.

dp[i][j-1]

Hence,

only the previous row and current row are required.

------------------------------------------------------------

Replace

dp[i-1]

by

prev

Replace

dp[i]

by

cur

------------------------------------------------------------

Transition

If characters match

cur[j]

=

1+prev[j-1]

Otherwise

cur[j]

=

max(prev[j],cur[j-1])

After completing one row,

copy

cur

into

prev.

====================================================================
TIME COMPLEXITY
====================================================================

O(N*M)

====================================================================
SPACE COMPLEXITY
====================================================================

O(M)
*/

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {

        int n=text1.size();
        int m=text2.size();

        vector<int> prev(m+1,-1);
        vector<int> cur(m+1,-1);

        // Base Case
        for(int j=0;j<=m;j++)
            prev[j]=0;

        cur[0]=0;

        for(int i=1;i<=n;i++){

            cur[0]=0;

            for(int j=1;j<=m;j++){

                if(text1[i-1]==text2[j-1])
                    cur[j]=1+prev[j-1];

                else
                    cur[j]=max(prev[j],cur[j-1]);
            }

            prev=cur;
        }

        return prev[m];
    }
};