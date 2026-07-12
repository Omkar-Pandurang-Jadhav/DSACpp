/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.*/


/*
====================================================================
INTUITION
====================================================================

Let f(n,m) represent whether

s[0...n-1]

matches

p[0...m-1].

------------------------------------------------------------

Case 1

If both strings become empty,

a match is found.

Return true.

------------------------------------------------------------

Case 2

If the pattern becomes empty but the string
still has characters,

matching is impossible.

Return false.

------------------------------------------------------------

Case 3

If the string becomes empty but the pattern
still has characters,

the pattern can match only if all remaining
characters are '*'.

------------------------------------------------------------

Case 4

If current characters match or the pattern
contains '?',

move both pointers.

------------------------------------------------------------

Case 5

If the pattern contains '*',

there are two possibilities.

1. '*' matches one character

Move only the string pointer.

2. '*' matches an empty string

Move only the pattern pointer.

Take logical OR.

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

    bool f(string s,string p,int n,int m,vector<vector<int>> &dp){

        // Both strings exhausted
        if(n==0 && m==0)
            return true;

        // Pattern exhausted
        if(m==0 && n>0)
            return false;

        // String exhausted
        if(n==0 && m>0){

            for(int i=1;i<=m;i++){
                if(p[i-1]!='*')
                    return false;
            }

            return true;
        }

        if(dp[n][m]!=-1)
            return dp[n][m];

        // Characters match or '?'
        if(s[n-1]==p[m-1] || p[m-1]=='?')
            return dp[n][m]=f(s,p,n-1,m-1,dp);

        // '*'
        if(p[m-1]=='*')
            return dp[n][m]=f(s,p,n-1,m,dp) ||
                            f(s,p,n,m-1,dp);

        // Characters do not match
        return dp[n][m]=false;
    }

    bool isMatch(string s,string p){

        int n=s.size();
        int m=p.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return f(s,p,n,m,dp);
    }
};