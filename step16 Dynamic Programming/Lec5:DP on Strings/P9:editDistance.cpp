/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.*/

/*
====================================================================
INTUITION
====================================================================

The goal of this problem is to convert word1 into word2 using the
minimum number of operations. Unlike the LCS problem, where we only
compare characters, here we are allowed to perform three operations:
Insert, Delete and Replace. Therefore, whenever the current characters
do not match, we must decide which operation gives the minimum cost.

Let f(n,m) represent the minimum number of operations required to
convert word1[0...n] into word2[0...m].

If the current characters match, i.e. word1[n] == word2[m], no
operation is required because these characters are already equal.
Hence, we simply move both pointers backward and solve the remaining
subproblem, i.e. f(n-1,m-1).

If the current characters do not match, we have three possible
operations.

The first operation is Insert. We insert the current character of
word2 into word1. After inserting, the current character of word2 has
been matched, so only the pointer of word2 moves backward while the
pointer of word1 remains at the same position. Therefore, the cost of
this operation is 1 + f(n,m-1).

The second operation is Delete. We delete the current character of
word1. Since that character is removed, only the pointer of word1
moves backward while the pointer of word2 remains unchanged. Hence,
the cost becomes 1 + f(n-1,m).

The third operation is Replace. We replace the current character of
word1 with the current character of word2. After replacement, both
characters become equal, so both pointers move backward. Therefore,
the cost becomes 1 + f(n-1,m-1).

Since our objective is to perform the minimum number of operations, we
take the minimum among Insert, Delete and Replace.

The first base case occurs when word1 becomes empty (n < 0). If word2
still contains m+1 characters, the only possible operation is to
insert all the remaining characters of word2 into word1. Hence, the
answer is m+1.

The second base case occurs when word2 becomes empty (m < 0). If
word1 still contains n+1 characters, the only possible operation is
to delete all the remaining characters of word1. Hence, the answer is
n+1.

====================================================================
TIME COMPLEXITY
====================================================================

O(N*M)

====================================================================
SPACE COMPLEXITY
====================================================================

O(N*M) for the DP table
+
O(N+M) auxiliary recursion stack.
*/

class Solution {
public:

    int f(string &s1,string &s2,int n,int m,vector<vector<int>> &dp){

        // word1 finished
        if(n<0)
            return m+1;

        // word2 finished
        if(m<0)
            return n+1;

        // Already computed
        if(dp[n][m]!=-1)
            return dp[n][m];

        // Characters match
        if(s1[n]==s2[m])
            return dp[n][m]=f(s1,s2,n-1,m-1,dp);

        // Minimum among Insert, Delete and Replace
        return dp[n][m]=1+min(
                              min(f(s1,s2,n-1,m,dp),
                                  f(s1,s2,n,m-1,dp)),
                              f(s1,s2,n-1,m-1,dp)
                             );
    }

    int minDistance(string word1,string word2){

        int n=word1.size();
        int m=word2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return f(word1,word2,n-1,m-1,dp);
    }
};