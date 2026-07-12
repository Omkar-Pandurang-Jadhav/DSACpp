/*
Problem statement
You are given two strings ‘s1’ and ‘s2’.



Return the longest common subsequence of these strings.



If there’s no such string, return an empty string. If there are multiple possible 
answers, return any such string.



Note:
Longest common subsequence of string ‘s1’ and ‘s2’ is the longest subsequence of 
‘s1’ that is also a subsequence of ‘s2’. A ‘subsequence’ of ‘s1’ is a string that can be formed by deleting one or more 
(possibly zero) characters from ‘s1’.


Example:
Input: ‘s1’  = “abcab”, ‘s2’ = “cbab”

Output: “bab”

Explanation:
“bab” is one valid longest subsequence present in both strings ‘s1’ , ‘s2’.


Detailed explanation ( Input/output format, Notes, Images
*/

/*
====================================================================
INTUITION
====================================================================

Instead of returning the length of the LCS,

we return the actual LCS string.

------------------------------------------------------------

Case 1 : Characters Match

If

s1[n] == s2[m]

then this character must be part of the LCS.

So,

find the LCS of the remaining prefixes

and append the current character.

LCS

=

LCS(n-1,m-1) + current character

------------------------------------------------------------

Case 2 : Characters Do Not Match

We have two choices.

1.

Ignore current character of s1

2.

Ignore current character of s2

Compute both strings and return the longer one.

------------------------------------------------------------

Base Case

If either string becomes empty,

there is no common subsequence.

Return an empty string.

====================================================================
TIME COMPLEXITY
====================================================================

Exponential

Many overlapping recursive calls.

====================================================================
SPACE COMPLEXITY
====================================================================

O(N+M)

Auxiliary recursion stack.
*/

#include<bits/stdc++.h>

string f(string &s1,string &s2,int n,int m){

    if(n<0 || m<0)
        return "";

    // Characters match
    if(s1[n]==s2[m])
        return f(s1,s2,n-1,m-1)+s1[n];

    // Ignore character from first string
    string t1=f(s1,s2,n-1,m);

    // Ignore character from second string
    string t2=f(s1,s2,n,m-1);

    // Return longer subsequence
    if(t1.size()>t2.size())
        return t1;

    return t2;
}

string findLCS(int n,int m,string &s1,string &s2){

    return f(s1,s2,n-1,m-1);
}


/*
====================================================================
INTUITION
====================================================================

The recursive state

dp[n][m]

stores

The actual LCS string of

s1[0...n]

and

s2[0...m].

If a state has already been computed,

reuse the stored string instead of solving it again.

====================================================================
TIME COMPLEXITY
====================================================================

O(N*M*L)

L is the average length of the stored strings.

====================================================================
SPACE COMPLEXITY
====================================================================

O(N*M*L)

DP table stores strings.

+

O(N+M)

Auxiliary recursion stack.
*/

#include<bits/stdc++.h>

string f(string &s1,string &s2,int n,int m,vector<vector<string>> &dp){

    if(n<0 || m<0)
        return "";

    if(dp[n][m]!="")
        return dp[n][m];

    // Characters match
    if(s1[n]==s2[m])
        return dp[n][m]=f(s1,s2,n-1,m-1,dp)+s1[n];

    // Ignore character from first string
    string t1=f(s1,s2,n-1,m,dp);

    // Ignore character from second string
    string t2=f(s1,s2,n,m-1,dp);

    // Store longer subsequence
    if(t1.size()>t2.size())
        return dp[n][m]=t1;

    return dp[n][m]=t2;
}

string findLCS(int n,int m,string &s1,string &s2){

    vector<vector<string>> dp(n,vector<string>(m,""));

    return f(s1,s2,n-1,m-1,dp);
}



/*
====================================================================
INTUITION
====================================================================

Instead of storing the LCS length,

store the actual LCS string.

------------------------------------------------------------

Right Shift of Index

Recursion uses

n<0

or

m<0

as the base case.

Negative indices cannot be represented in a DP table.

So,

Original Index

-1 0 1 2 ...

becomes

0 1 2 3 ...

------------------------------------------------------------

dp[i][j]

represents

The actual LCS string of

s1[0...i-1]

and

s2[0...j-1].

------------------------------------------------------------

Transition

If characters match,

append the current character.

dp[i][j]

=

dp[i-1][j-1] + current character

------------------------------------------------------------

Otherwise,

compare

dp[i-1][j]

and

dp[i][j-1]

and keep the longer string.

====================================================================
TIME COMPLEXITY
====================================================================

O(N*M*L)

L is the average length of stored strings.

====================================================================
SPACE COMPLEXITY
====================================================================

O(N*M*L)

Entire DP table stores strings.
*/

#include<bits/stdc++.h>

string findLCS(int n,int m,string &s1,string &s2){

    vector<vector<string>> dp(n+1,vector<string>(m+1,""));

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            // Characters match
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+s1[i-1];

            else{

                string t1=dp[i-1][j];
                string t2=dp[i][j-1];

                if(t1.size()>t2.size())
                    dp[i][j]=t1;

                else
                    dp[i][j]=t2;
            }
        }
    }

    return dp[n][m];
}




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

instead of storing the entire DP table,

we only need

1.

Previous Row

2.

Current Row

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

If characters match,

append the current character to the LCS obtained from
the previous diagonal cell.

cur[j]

=

prev[j-1] + current character

------------------------------------------------------------

Otherwise,

compare

prev[j]

and

cur[j-1]

and keep the longer string.

------------------------------------------------------------

After finishing one complete row,

copy

cur

into

prev

and continue with the next row.

====================================================================
TIME COMPLEXITY
====================================================================

O(N * M * L)

L is the average length of the stored strings.

String concatenation and copying take O(L).

====================================================================
SPACE COMPLEXITY
====================================================================

O(M * L)

Only two rows of strings are stored.
*/

#include<bits/stdc++.h>

string findLCS(int n, int m, string &s1, string &s2){

    vector<string> prev(m+1,"");
    vector<string> cur(m+1);

    // Base Case
    cur[0]="";

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            // Characters match
            if(s1[i-1]==s2[j-1]){

                cur[j]=prev[j-1]+s1[i-1];
            }

            // Characters do not match
            else{

                string t1=prev[j];
                string t2=cur[j-1];

                if(t1.size()>t2.size())
                    cur[j]=t1;
                else
                    cur[j]=t2;
            }
        }

        // Move current row to previous row
        prev=cur;
    }

    return prev[m];
}