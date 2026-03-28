
/*
You are given the arrival times arr[] and departure times dep[] of all trains that arrive at a 
railway station on the same day. Your task is to determine the minimum number of platforms required 
at the station to ensure that no train is kept waiting.

At any given time, the same platform cannot be used for both the arrival of one train and the departure of 
another. Therefore, when two trains arrive at the same time, or when one arrives before another departs, 
additional platforms are required to accommodate both trains.

Examples:

Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
Output: 3
Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.

Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
Output: 1
Explanation: All train times are mutually exclusive. So we need only one platform

Input: arr[] = [1000, 935, 1100], dep[] = [1200, 1240, 1130]
Output: 3
Explanation: All 3 trains have to be there from 11:00 to 11:30
*/



class Solution {
  public:
    /*
    Problem:
    ---------
    Given arrival and departure times of trains at a station, 
    find the minimum number of platforms required such that no train waits.

    Approach:
    -----------
    - Use the **event sorting (line sweep)** technique:
      1. Treat every arrival and departure as an event.
         - Represent arrival as (time, 0)
         - Represent departure as (time, 1)
      2. Store all these events in a vector of pairs.
      3. Sort the events:
         - First by time
         - If times are equal, arrival (0) comes before departure (1)
      4. Traverse through the sorted events:
         - If it's an arrival → increment count of platforms needed
         - If it's a departure → decrement count
         - Track the maximum platforms needed during the process.

    Time Complexity:
    -----------------
    - O(N log N)  
      (for sorting 2N events)

    Space Complexity:
    -----------------
    - O(N)  
      (for storing 2N events)

    */

    // Comparator to sort events
    static bool comp(pair<int,int> &a, pair<int,int> &b){
        if(a.first < b.first) return true;
        else if(a.first > b.first) return false;
        else return a.second < b.second;  // arrival (0) before departure (1) if same time
    }

    int findPlatform(vector<int>& arr, vector<int>& dep) {
        vector<pair<int,int>> events;
        int n = arr.size();

        // Push arrival as (time, 0) and departure as (time, 1)
        for(int i = 0; i < n; i++){
            events.push_back({arr[i], 0});  // arrival
            events.push_back({dep[i], 1});  // departure
        }

        // Sort events by time, arrivals before departures at same time
        sort(events.begin(), events.end(), comp);

        int count = 0;  // current platforms needed
        int maxPlatforms = 0;  // maximum platforms needed at any time

        // Process all events in sorted order
        for(int i = 0; i < 2 * n; i++){
            if(events[i].second == 0) 
                count++;  // train arrives → need platform
            else 
                count--;  // train departs → free platform

            maxPlatforms = max(maxPlatforms, count);
        }

        return maxPlatforms;
    }
};
