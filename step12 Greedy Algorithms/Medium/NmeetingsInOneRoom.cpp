# include<bits/stdc++.h>
using namespace std;


/*
You are given timings of n meetings in the form of (start[i], end[i]) 
where start[i] is the start time of meeting i and end[i] is the finish time 
of meeting i. Return the maximum number of meetings that can be accommodated 
in a single meeting room, when only one meeting can be held in the meeting room 
at a particular time. 

Note: The start time of one chosen meeting can't be equal to the 
end time of the other chosen meeting.

Examples :

Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. 
The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
Input: start[] = [10, 12, 20], end[] = [20, 25, 30]
Output: 1
Explanation: Only one meetings can be held with given start and end timings.
Input: start[] = [1, 2], end[] = [100, 99]
Output: 1
Constraints:
1 ≤ n ≤ 105
0 ≤ start[i] < end[i] ≤ 106*/

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.

    /*
    Approach:
    -----------
    1. We are given two arrays: `start` and `end` representing start and end times of meetings.
    2. The task is to select the maximum number of non-overlapping meetings that can be scheduled 
       in a single room.

    3. To do this:
       - Create a struct `meeting` to hold start time, end time, and original position.
       - Store each meeting's start, end, and position into an array of meetings.
       - Sort the meetings based on their end times. 
         If two meetings have the same end time, pick the one that appeared earlier in the input.
         (This ensures deterministic ordering.)

    4. Initialize:
       - A limit variable to track the ending time of the last selected meeting.
       - A vector `ans` to store positions (for internal use — optional here).

    5. Iterate through the sorted meetings:
       - If the start time of the current meeting is greater than the limit (end time of last selected meeting),
         select it, update the limit to this meeting's end time, and increment the count.

    6. Finally, return the number of selected meetings, i.e., ans.size().

    Time Complexity:
    ----------------
    - Sorting the meetings: O(N log N)
    - Iterating through the meetings: O(N)
    - Total: O(N log N)

    Space Complexity:
    -----------------
    - O(N) for meetings array and ans vector
    */

    struct meeting{
        int start;
        int end;
        int pos;
    };

    // Comparator to sort meetings based on end time, then by position if tie
    static bool comp(struct meeting &a,struct meeting &b){
        if(a.end < b.end) return true;
        else if(a.end > b.end) return false;
        else return a.pos < b.pos;
    }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        struct meeting m[n];
        
        // Storing start, end and position for each meeting
        for(int i = 0; i < n; i++){
            m[i].start = start[i];
            m[i].end = end[i];
            m[i].pos = i;
        }

        // Sorting meetings based on end time (earliest ending meeting first)
        sort(m, m+n, comp);

        vector<int> ans;
        ans.push_back(m[0].pos); // Always select the first meeting
        int limit = m[0].end;

        // Check for non-overlapping meetings
        for(int i = 1; i < n; i++){
            if(m[i].start > limit){
                limit = m[i].end;
                ans.push_back(m[i].pos);
            }
        }

        return ans.size(); // Number of meetings scheduled
    }
};
