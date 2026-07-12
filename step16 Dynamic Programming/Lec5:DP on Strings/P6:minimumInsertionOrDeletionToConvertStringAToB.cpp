/*
====================================================================
INTUITION
====================================================================

We are allowed to perform only one operation:

Delete a character from either string.

------------------------------------------------------------

Instead of thinking about what to delete,

think about what we should keep.

The characters that should remain in both strings
are the

Longest Common Subsequence (LCS).

Those characters already appear in both strings
in the correct order.

So we never delete them.

------------------------------------------------------------

Suppose

word1 = "sea"

word2 = "eat"

LCS = "ea"

Length of LCS = 2

Characters to delete from word1

=

Length(word1)

-

LCS

=

3-2=1

Delete

's'

------------------------------------------------------------

Characters to delete from word2

=

Length(word2)

-

LCS

=

3-2=1

Delete

't'

Total deletions

=

1+1

=

2

------------------------------------------------------------

General Formula

Delete from first string

=

n-LCS

Delete from second string

=

m-LCS

Therefore,

Minimum Deletions

=

(n-LCS)

+

(m-LCS)

=

n+m-2×LCS

====================================================================
TIME COMPLEXITY
====================================================================

O(N*M)

LCS using Memoization.

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

        // Characters match
        if(s1[n]==s2[m])
            return dp[n][m]=1+f(s1,s2,n-1,m-1,dp);

        // Ignore one character
        return dp[n][m]=max(f(s1,s2,n-1,m,dp),f(s1,s2,n,m-1,dp));
    }

    int minDistance(string word1, string word2) {

        int n=word1.size();
        int m=word2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        // Length of Longest Common Subsequence
        int lcs=f(word1,word2,n-1,m-1,dp);

        // Minimum deletions required
        return n+m-2*lcs;
    }
};