/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove 
to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

 */

 class Solution {
public:
    /*
    Problem:
    ------------
    Given N intervals, find the minimum number of intervals you need to remove 
    to make the rest non-overlapping.

    Approach (Greedy — Activity Selection Pattern):
    ------------------------------------------------
    1️⃣ Treat each interval as a meeting with a start and end time.
    2️⃣ Sort intervals based on earliest end time.
    3️⃣ Iterate through intervals:
        - Always select the interval if its start time is >= end time of last selected interval.
        - Keep track of number of selected non-overlapping intervals.
    4️⃣ Total removals = N - (number of selected intervals)

    Time Complexity:
    ----------------
    O(N log N) — due to sorting

    Space Complexity:
    ----------------
    O(N) — for meetings array and result vector
    */

    struct meeting{
        int start;
        int end;
        int pos;
    };

    // Comparator to sort meetings based on end time, then by position
    static bool comp(struct meeting &a, struct meeting &b){
        if(a.end < b.end) return true;
        else if(a.end > b.end) return false;
        else return a.pos < b.pos;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;

        // Prepare meeting array
        struct meeting m[n];
        for(int i = 0; i < n; i++){
            m[i].start = intervals[i][0];
            m[i].end = intervals[i][1];
            m[i].pos = i;
        }

        // Sort intervals by end time
        sort(m, m + n, comp);

        vector<int> ans;  // to store selected meeting positions
        ans.push_back(m[0].pos);  // select first interval
        int limit = m[0].end;

        // Select non-overlapping intervals
        for(int i = 1; i < n; i++){
            if(m[i].start >= limit){
                limit = m[i].end;
                ans.push_back(m[i].pos);
            }
        }

        // Number of intervals to remove = total - selected
        return n - ans.size();
    }
};
