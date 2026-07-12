/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. 
If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in
 the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"

*/

/*
====================================================================
INTUITION
====================================================================

A Supersequence is a string that contains both strings
as subsequences.

Our goal is to construct the

Shortest Common Supersequence (SCS).

------------------------------------------------------------

Observation

The common characters between both strings
should appear only once.

The common part is exactly the

Longest Common Subsequence (LCS).

Therefore,

1.

Find the LCS DP table.

2.

Use the DP table to reconstruct the answer.

------------------------------------------------------------

Reconstruction

Start from

(i=n , j=m)

------------------------------------------------------------

Case 1

Characters match.

This character belongs to both strings.

Add it only once.

Move diagonally.

i--

j--

------------------------------------------------------------

Case 2

Characters do not match.

Compare

dp[i-1][j]

and

dp[i][j-1]

If

dp[i-1][j] > dp[i][j-1]

Move upward.

Add

str1[i-1]

Otherwise

Move left.

Add

str2[j-1]

------------------------------------------------------------

After one string finishes,

append all remaining characters of the other string.

The constructed string is the

Shortest Common Supersequence.

====================================================================
TIME COMPLEXITY
====================================================================

LCS

O(N*M)

Reconstruction

O(N+M)

Overall

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

        if(n==0 || m==0)
            return 0;

        if(dp[n][m]!=-1)
            return dp[n][m];

        // Characters match
        if(s1[n-1]==s2[m-1])
            return dp[n][m]=1+f(s1,s2,n-1,m-1,dp);

        // Ignore one character
        return dp[n][m]=max(f(s1,s2,n-1,m,dp),
                            f(s1,s2,n,m-1,dp));
    }

    string shortestCommonSupersequence(string str1, string str2) {

        int n=str1.size();
        int m=str2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        // Fill the LCS DP table
        f(str1,str2,n,m,dp);

        int i=n;
        int j=m;

        string ans="";

        // Reconstruct the SCS
        while(i>0 && j>0){

            // Common character
            if(str1[i-1]==str2[j-1]){

                i--;
                j--;

                ans=str1[i]+ans;
            }

            // Move upward
            else if(dp[i-1][j]>dp[i][j-1]){

                i--;

                ans=str1[i]+ans;
            }

            // Move left
            else{

                j--;

                ans=str2[j]+ans;
            }
        }

        // Remaining characters of first string
        while(i>0){

            i--;

            ans=str1[i]+ans;
        }

        // Remaining characters of second string
        while(j>0){

            j--;

            ans=str2[j]+ans;
        }

        return ans;
    }
};