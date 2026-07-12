/*
====================================================================
INTUITION
====================================================================

This problem is different from Longest Common Subsequence.

------------------------------------------------------------

Longest Common Subsequence

Characters can be skipped.

Example

abcde

ace

LCS = ace

------------------------------------------------------------

Longest Common Substring

Characters must be continuous.

Example

abcde

ace

Common Substrings

a

c

e

Length = 1

"ace" is NOT a substring because the characters
are not consecutive.

------------------------------------------------------------

DP State

dp[i][j]

represents

Length of the longest common substring ending at

str1[i-1]

and

str2[j-1].

Notice the words

"ending at"

This is different from LCS.

------------------------------------------------------------

Case 1 : Characters Match

Suppose

str1[i-1] == str2[j-1]

Then the common substring can be extended.

Current Length

=

1

+

Previous Diagonal

Therefore,

dp[i][j]

=

1 + dp[i-1][j-1]

Update the global maximum answer.

------------------------------------------------------------

Case 2 : Characters Do Not Match

Suppose

str1[i-1] != str2[j-1]

The current substring immediately breaks.

Since a substring must be continuous,

we cannot extend anything further.

Hence,

Current common substring length becomes

0.

Therefore,

dp[i][j]

=

0

------------------------------------------------------------

Why not use

max(dp[i-1][j],dp[i][j-1])

like LCS?

Because that would allow skipping characters.

Skipping characters is allowed in a subsequence,

but NOT in a substring.

A substring must remain continuous.

Example

str1 = "abc"

str2 = "adc"

At

'b'

and

'd'

characters do not match.

The substring

must stop there.

It cannot continue after skipping.

Therefore,

we reset the length to

0.

====================================================================
TIME COMPLEXITY
====================================================================

O(N*M)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N*M)
*/

#include<bits/stdc++.h>

int lcs(string &str1, string &str2){

    int n=str1.size();
    int m=str2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    // Base Cases
    for(int j=0;j<=m;j++)
        dp[0][j]=0;

    for(int i=0;i<=n;i++)
        dp[i][0]=0;

    int maxi=0;

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            // Characters match
            if(str1[i-1]==str2[j-1]){

                dp[i][j]=1+dp[i-1][j-1];

                maxi=max(maxi,dp[i][j]);
            }

            // Characters do not match
            else{

                // Current substring breaks
                dp[i][j]=0;
            }
        }
    }

    return maxi;
}