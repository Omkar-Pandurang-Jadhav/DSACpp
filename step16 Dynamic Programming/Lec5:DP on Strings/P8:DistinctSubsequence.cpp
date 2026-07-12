/*
====================================================================
INTUITION
====================================================================

We need to count the number of distinct subsequences of

s

that are equal to

t.

------------------------------------------------------------

At every position,

we decide whether to use the current character of

s

or skip it.

------------------------------------------------------------

Case 1 : Characters Match

Suppose

s[n] == t[m]

Now we have two choices.

Choice 1

Take this character.

If we take it,

both strings move backward.

f(n-1,m-1)

------------------------------------------------------------

Choice 2

Do not take this character.

Maybe another occurrence of the same character later
can be used.

So,

only

s

moves backward.

f(n-1,m)

------------------------------------------------------------

Therefore,

Total Ways

=

Take

+

Not Take

------------------------------------------------------------

Case 2 : Characters Do Not Match

Suppose

s[n] != t[m]

Current character of

s

cannot be used.

The only option is to skip it.

Hence,

f(n-1,m)

------------------------------------------------------------

Base Case 1

If

m<0

it means we have matched every character of

t.

One valid subsequence has been formed.

Return

1.

------------------------------------------------------------

Base Case 2

If

n<0

but

m>=0

the source string has finished,

while some characters of

t

are still left.

It is impossible to form

t.

Return

0.

====================================================================
TIME COMPLEXITY
====================================================================

O(2^N)

Every character of s may either be taken or skipped.

====================================================================
SPACE COMPLEXITY
====================================================================

O(N+M)

Auxiliary recursion stack.
*/

class Solution {
public:

    int f(string s,string t,int n,int m){

        // Entire target string matched
        if(m<0)
            return 1;

        // Source string finished before target
        if(n<0)
            return 0;

        // Characters match
        if(s[n]==t[m])
            return f(s,t,n-1,m-1)+
                   f(s,t,n-1,m);

        // Characters do not match
        return f(s,t,n-1,m);
    }

    int numDistinct(string s,string t){

        int n=s.size();
        int m=t.size();

        return f(s,t,n-1,m-1);
    }
};

// Tabulation


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

    int numDistinct(string s, string t) {

        int n=s.size();
        int m=t.size();

        vector<vector<double>> dp(n+1,vector<double>(m+1,-1));

        // Empty target can always be formed
        for(int i=0;i<=n;i++)
            dp[i][0]=1;

        // Non-empty target cannot be formed from empty source
        for(int j=1;j<=m;j++)
            dp[0][j]=0;

        // Fill DP Table
        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                // Characters match
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];

                // Characters do not match
                else
                    dp[i][j]=dp[i-1][j];
            }
        }

        return (int)dp[n][m];
    }
};


// Space Optimization

===================================================================
TIME COMPLEXITY
====================================================================

O(N*M)

====================================================================
SPACE COMPLEXITY
====================================================================

O(M)

Only two rows are stored.
*/

class Solution {
public:

    int numDistinct(string s, string t) {

        int n=s.size();
        int m=t.size();

        vector<double> prev(m+1,0);
        vector<double> cur(m+1,0);

        // Base Case
        prev[0]=1;
        cur[0]=1;

        for(int i=1;i<=n;i++){

            cur[0]=1;

            for(int j=1;j<=m;j++){

                // Characters match
                if(s[i-1]==t[j-1])
                    cur[j]=prev[j-1]+prev[j];

                // Characters do not match
                else
                    cur[j]=prev[j];
            }

            prev=cur;
        }

        return (int)prev[m];
    }
};


/*
====================================================================
INTUITION
====================================================================

From the space optimized solution,

observe that

cur[j]

depends only on

prev[j]

and

prev[j-1].

There is no dependency on

cur[j-1].

Hence,

we can reduce the DP from two arrays
to a single array.

------------------------------------------------------------

Initially,

the single array

prev

stores the values of the previous row.

While processing the current row,

we overwrite the same array.

------------------------------------------------------------

Why do we iterate from Right to Left?

Suppose

dp[j]

needs

dp[j]

and

dp[j-1]

from the previous row.

If we move

Left to Right,

dp[j-1]

would already be updated,

and we would lose its old value.

------------------------------------------------------------

Therefore,

iterate from

Right to Left.

This guarantees

dp[j-1]

still contains the previous row value
when it is needed.

------------------------------------------------------------

Why is there no else condition?

The recurrence is

If characters match

dp[j]

=

prev[j-1]

+

prev[j]

Otherwise

dp[j]

=

prev[j]

In the one-array solution,

dp[j]

already stores

prev[j].

So,

when characters do not match,

the correct value is already present.

Nothing needs to be updated.

Therefore,

the else condition disappears.

====================================================================
TIME COMPLEXITY
====================================================================

O(N*M)

====================================================================
SPACE COMPLEXITY
====================================================================

O(M)

Only one DP array is used.
*/

class Solution {
public:

    int numDistinct(string s, string t) {

        int n=s.size();
        int m=t.size();

        vector<double> prev(m+1,0);

        // Base Case
        prev[0]=1;

        for(int i=1;i<=n;i++){

            // Traverse from Right to Left
            for(int j=m;j>=1;j--){

                // Characters match
                if(s[i-1]==t[j-1])
                    prev[j]=prev[j-1]+prev[j];

                // No else needed because
                // prev[j] already stores the previous row value.
            }
        }

        return (int)prev[m];
    }
};