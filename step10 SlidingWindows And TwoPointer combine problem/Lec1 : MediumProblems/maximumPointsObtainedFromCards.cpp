/*
There are several cards arranged in a row, and each card has an associated number of 
points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. 
You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can 
obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.*/
/*
============================================================
MAXIMUM POINTS FROM CARDS (2 APPROACHES)
============================================================

PROBLEM:
Pick exactly k cards from either start or end
to maximize total score.

============================================================


------------------------------------------------------------
1️⃣ PREFIX + SUFFIX (LEFT + RIGHT PICKING)
------------------------------------------------------------

APPROACH:
- First take all k cards from left → initial sum
- Then gradually:
    → remove one from left
    → add one from right
- Try all combinations:
    x from left + (k-x) from right

------------------------------------------------------------

TIME COMPLEXITY:
O(2k) ≈ O(k)

→ First loop: k
→ Second loop: k

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

------------------------------------------------------------
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(k==0) return 0;
        if(k==cardPoints.size()) return accumulate(cardPoints.begin(),cardPoints.end(),0);

        int lsum=0;
        int rsum=0;
        int sum=0;

        // take all k from left
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
            lsum+=cardPoints[i];
        }

        int rightIndex=cardPoints.size()-1;

        // shift from left to right
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[rightIndex];
            rightIndex-=1;
            sum=max(sum,lsum+rsum);
        }

        return sum;
    }
};



/*
------------------------------------------------------------
2️⃣ SLIDING WINDOW (MIN SUBARRAY REMOVAL ⭐)
------------------------------------------------------------

APPROACH:
- Instead of picking k cards,
  remove (n-k) continuous cards
- Find minimum subarray of size (n-k)
- Answer = totalSum - minSubarraySum

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ First loop: n-k
→ Second loop: k
→ Total ≈ n

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

------------------------------------------------------------

KEY INSIGHT:
- Taking k from ends = leaving middle n-k
- Minimize the middle → maximize ends

------------------------------------------------------------
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(k==0) return 0;

        int minSubArray=0;
        int sum=0;
        int currSum=0;

        // initial window (size n-k)
        for(int i=0;i<cardPoints.size()-k;i++){
            currSum+=cardPoints[i];
            sum+=cardPoints[i];
        }

        minSubArray=currSum;

        // slide window
        for(int i=cardPoints.size()-k;i<cardPoints.size();i++){
            currSum=currSum-cardPoints[i-(cardPoints.size()-k)]+cardPoints[i];
            minSubArray=min(minSubArray,currSum);
            sum+=cardPoints[i];
        }

        if(k==cardPoints.size()) return sum;

        return sum-minSubArray;
    }
};



/*
============================================================
FINAL COMPARISON
============================================================

| Approach            | Time Complexity | Space |
|---------------------|----------------|-------|
| Prefix + Suffix     | O(2k) ⭐       | O(1)  |
| Sliding Window      | O(n) ⭐        | O(1)  |

============================================================

INSIGHT:
- First approach tries all left/right combinations
- Second approach converts problem to min subarray

============================================================
*/