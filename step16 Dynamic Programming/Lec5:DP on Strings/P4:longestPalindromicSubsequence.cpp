/*
====================================================================
INTUITION
====================================================================

A palindrome reads the same from both directions.

Reverse the string.

Now the problem becomes

Longest Common Subsequence

between

Original String

and

Reversed String.

The recursion is exactly the same as LCS.

------------------------------------------------------------

Case 1

Characters match.

Take the character.

1 + LCS(i-1,j-1)

------------------------------------------------------------

Case 2

Characters do not match.

Either ignore one character from

the original string

or

the reversed string.

Take the maximum.

------------------------------------------------------------

Base Case

If either string becomes empty,

return 0.

====================================================================
TIME COMPLEXITY
====================================================================

O(2^(2N))

====================================================================
SPACE COMPLEXITY
====================================================================

O(2N)

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

    int longestPalindromeSubseq(string s) {

        int n=s.size();

        string s2=s;

        reverse(s.begin(),s.end());

        string temp=s2;
        s2=s;
        s=temp;

        return f(s,s2,n-1,n-1);
    }
};


/*
====================================================================
INTUITION
====================================================================

This is the Memoization version of LCS.

dp[n][m]

stores

The length of the Longest Palindromic Subsequence

considering

s1[0...n]

and

s2[0...m].

Repeated states are stored and reused.

====================================================================
TIME COMPLEXITY
====================================================================

O(N²)

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

        if(s1[n]==s2[m])
            return dp[n][m]=1+f(s1,s2,n-1,m-1,dp);

        return dp[n][m]=max(f(s1,s2,n-1,m,dp),f(s1,s2,n,m-1,dp));
    }

    int longestPalindromeSubseq(string s) {

        int n=s.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        string s2=s;

        reverse(s.begin(),s.end());

        string temp=s2;
        s2=s;
        s=temp;

        return f(s,s2,n-1,n-1,dp);
    }
};


/*
====================================================================
INTUITION
====================================================================

After reversing the string,

the problem becomes

Longest Common Subsequence.

------------------------------------------------------------

Right Shift of Index

Original Index

-1 0 1 ...

becomes

0 1 2 ...

------------------------------------------------------------

dp[i][j]

represents

LCS of

s[0...i-1]

and

reverse(s)[0...j-1].

------------------------------------------------------------

Transition

If characters match

dp[i][j]

=

1+dp[i-1][j-1]

Otherwise

dp[i][j]

=

max(dp[i-1][j],dp[i][j-1])

====================================================================
TIME COMPLEXITY
====================================================================

O(N²)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N²)
*/

class Solution {
public:

    int longestPalindromeSubseq(string s) {

        int n=s.size();

        string s2=s;

        reverse(s.begin(),s.end());

        string temp=s2;
        s2=s;
        s=temp;

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        // Base Cases
        for(int i=0;i<=n;i++)
            dp[i][0]=0;

        for(int j=0;j<=n;j++)
            dp[0][j]=0;

        // Fill DP Table
        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++){

                if(s[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];

                else
                    dp[i][j]=max(dp[i-1][j],
                                 dp[i][j-1]);
            }
        }

        return dp[n][n];
    }
};


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

Therefore,

replace

dp[i-1]

by

prev

replace

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

O(N²)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N)
*/

class Solution {
public:

    int longestPalindromeSubseq(string s) {

        int n=s.size();

        string s2=s;

        reverse(s.begin(),s.end());

        string temp=s2;
        s2=s;
        s=temp;

        vector<int> prev(n+1,-1);
        vector<int> cur(n+1,-1);

        // Base Case
        for(int j=0;j<=n;j++)
            prev[j]=0;

        cur[0]=0;

        for(int i=1;i<=n;i++){

            cur[0]=0;

            for(int j=1;j<=n;j++){

                if(s[i-1]==s2[j-1])
                    cur[j]=1+prev[j-1];

                else
                    cur[j]=max(prev[j],cur[j-1]);
            }

            prev=cur;
        }

        return prev[n];
    }
};