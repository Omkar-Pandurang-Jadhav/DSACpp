/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

 

Constraints:

    1 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 104

*/

class Solution {
public:
    /*
    Problem:
    -----------
    Given a collection of intervals, merge all overlapping intervals.

    Approach:
    -----------
    1️⃣ Sort the intervals based on start time.
    2️⃣ Initialize a temporary interval `temp` as the first interval.
    3️⃣ Iterate over intervals:
        - If current interval overlaps with `temp` (start ≤ temp.end)
            → merge by updating temp.end = max(temp.end, current.end)
        - Else
            → push `temp` to result and set temp = current interval.
    4️⃣ Finally, push the last `temp` interval.

    Time Complexity:
    ----------------
    O(N log N)
    - Sorting takes O(N log N)
    - One pass merge takes O(N)

    Space Complexity:
    ----------------
    O(N) for result vector.
    */

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Edge case: no intervals
        if(n == 0) return {};

        // 1️⃣ Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // 2️⃣ Start with first interval as temp
        vector<int> temp = intervals[0];

        // 3️⃣ Iterate through intervals
        for(auto it : intervals){
            if(it[0] <= temp[1]){
                // Overlap → merge intervals
                temp[1] = max(temp[1], it[1]);
            }
            else{
                // No overlap → save current merged interval
                ans.push_back(temp);
                temp = it;
            }
        }

        // 4️⃣ Push the final interval
        ans.push_back(temp);

        return ans;
    }
};
