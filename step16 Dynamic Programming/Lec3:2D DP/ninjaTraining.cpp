/*
============================================================
NINJA TRAINING - 4 APPROACHES
(Recursion, Memoization, Tabulation, Space Optimized)
============================================================

PROBLEM:
- N days
- Each day → 3 tasks (0,1,2)
- Cannot do same task on consecutive days
- Maximize total points

STATE:
dp[day][last] → max points till "day"
given last task done was "last"

last ∈ {0,1,2,3}
(3 means: no previous task)

============================================================


------------------------------------------------------------
1️⃣ PURE RECURSION
------------------------------------------------------------

APPROACH:
- Try all tasks except "last"
- Pick best

------------------------------------------------------------

TIME COMPLEXITY:
O(3^n) ❌

------------------------------------------------------------

SPACE COMPLEXITY:
O(n) (recursion stack)

------------------------------------------------------------
*/

int functions(int n,int last,vector<vector<int>>& points){
    if(n==0){
        int maxi=INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[n][i]);
            }
        }
        return maxi;
    }

    int maxi=INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point=points[n][i]+functions(n-1,i,points);
            maxi=max(maxi,point);
        }
    }

    return maxi;
}



/*
------------------------------------------------------------
2️⃣ MEMOIZATION (Top-Down DP)
------------------------------------------------------------

TIME COMPLEXITY:
O(n * 4 * 3) ≈ O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(n*4) + O(n) = O(n)

------------------------------------------------------------
*/

int functions(int n,int last,vector<vector<int>>& points,vector<vector<int>> &dp){

    if(n==0){
        int maxi=INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[n][i]);
            }
        }
        return maxi;
    }

    if(dp[n][last]!=-1) return dp[n][last];

    int maxi=INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point=points[n][i]+functions(n-1,i,points,dp);
            maxi=max(maxi,point);
        }
    }

    return dp[n][last]=maxi;
}



/*
------------------------------------------------------------
3️⃣ TABULATION (Bottom-Up DP)
------------------------------------------------------------

TIME COMPLEXITY:
O(n * 4 * 3) ≈ O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(n * 4)

------------------------------------------------------------
*/

int maximumPoints(vector<vector<int>>& mat) {

    int n = mat.size();

    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base case
    dp[0][0]=max(mat[0][1],mat[0][2]);
    dp[0][1]=max(mat[0][0],mat[0][2]);
    dp[0][2]=max(mat[0][0],mat[0][1]);
    dp[0][3]=max(mat[0][0],max(mat[0][1],mat[0][2]));

    for(int i=1;i<n;i++){
        for(int last=0;last<4;last++){

            dp[i][last]=0;

            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=mat[i][task]+dp[i-1][task];
                    dp[i][last]=max(dp[i][last],point);
                }
            }
        }
    }

    return dp[n-1][3];
}



/*
------------------------------------------------------------
4️⃣ SPACE OPTIMIZED (BEST)
------------------------------------------------------------

APPROACH:
- Only previous row needed

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(4) → O(1)

------------------------------------------------------------
*/

int maximumPoints(vector<vector<int>>& mat) {

    int n = mat.size();

    vector<int> prev(4,0), cur(4,0);

    // Base case
    prev[0]=max(mat[0][1],mat[0][2]);
    prev[1]=max(mat[0][0],mat[0][2]);
    prev[2]=max(mat[0][0],mat[0][1]);
    prev[3]=max(mat[0][0],max(mat[0][1],mat[0][2]));

    for(int i=1;i<n;i++){

        for(int last=0;last<4;last++){

            cur[last]=0;

            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=mat[i][task]+prev[task];
                    cur[last]=max(cur[last],point);
                }
            }
        }

        prev = cur; // move to next day
    }

    return prev[3];
}



/*
============================================================
FINAL COMPARISON
============================================================

| Approach        | Time      | Space        | Stack |
|----------------|-----------|--------------|-------|
| Recursion      | O(3^n) ❌  | O(n)         | O(n)  |
| Memoization    | O(n) ✅    | O(n)         | O(n)  |
| Tabulation     | O(n) ✅    | O(n)         | O(0)  |
| Space Optimized| O(n) ✅    | O(1) ⭐       | O(0)  |

============================================================

KEY TAKEAWAYS:
- Recursion → brute force
- Memoization → avoids recomputation
- Tabulation → iterative DP
- Space optimized → BEST for interviews

============================================================
*/