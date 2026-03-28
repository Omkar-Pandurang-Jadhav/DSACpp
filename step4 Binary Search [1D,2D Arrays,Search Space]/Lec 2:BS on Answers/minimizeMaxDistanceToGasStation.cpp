/*
We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1].
 Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to 
 find the smallest possible value of d. Find the answer exactly to 2 decimal places.
Note: stations is in a strictly increasing order.

Examples:

Input: stations[] = [1, 2, 3, 4, 5], k = 2
Output: 1.00
Explanation: Since all gaps are already equal (1 unit each), adding extra stations in between does not reduce the maximum distance.

Input: stations[] = [3, 6, 12, 19, 33], k = 3
Output: 6.00 
Explanation: The largest gap is 14 (between 19 and 33). Adding 2 stations there splits it into approx 4.67. The next largest gap is 7 
(between 12 and 19). Adding 1 station splits it into 3.5. Now the maximum gap left is 6.
*/



// Brute force
class Solution {
  public:
    /*
        Approach:
        ----------
        - We are given existing gas stations along a highway (stations[]).
        - We can add K extra gas stations anywhere between existing stations.
        - Goal: minimize the maximum distance between any two consecutive stations.

        Greedy Simulation:
        ------------------
        - Consider each interval between stations[i] and stations[i+1].
        - Keep track (in howMany[]) of how many new stations are inserted in that interval.
        - For each of the K extra stations:
            * Find the interval that currently has the largest "effective section length"
              (i.e., (stations[i+1]-stations[i]) / (howMany[i]+1)).
            * Place a new gas station in that interval (increment howMany[i]).
        - After distributing all K stations, recompute the maximum section length.
        - Return this as the minimized maximum distance.

        Example:
        --------
        stations = [1, 13], K = 1
        Initially: interval = 12
        Place 1 station → split into two intervals of length 6.
        Answer = 6.0

        Time Complexity:
        ----------------
        - Outer loop runs K times.
        - Inner loop runs (n-1) times to find the largest interval.
        - O(K * (n-1)) ≈ O(n*K).

        Space Complexity:
        -----------------
        - howMany[] of size (n-1).
        - O(n).
    */

    double minMaxDist(vector<int> &stations, int K) {
        int n = stations.size();
        if (n == 1) return 0; // No interval to split

        vector<int> howMany(n - 1, 0); // how many new stations in each interval

        // Place K new gas stations
        for (int gasStation = 1; gasStation <= K; gasStation++) {
            long double maxSection = -1;
            int maxId = -1;

            // Find the interval with the largest effective section length
            for (int i = 0; i < n - 1; i++) {
                long double diff = stations[i + 1] - stations[i];
                long double sectionLength = diff / (long double)(howMany[i] + 1);

                if (sectionLength > maxSection) {
                    maxSection = sectionLength;
                    maxId = i;
                }
            }

            // Place the new station in that interval
            howMany[maxId]++;
        }

        // Recompute the maximum distance after placing all stations
        long double maxi = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = stations[i + 1] - stations[i];
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            maxi = max(maxi, sectionLength);
        }

        return maxi;
    }
};


// Better Solution 
class Solution {
  public:
    /*
        Problem:
        --------
        - We have gas stations on a line (stations[]).
        - We can add at most K new gas stations.
        - Goal: minimize the maximum distance between adjacent stations.

        Approach (Greedy with Max-Heap / Priority Queue):
        -------------------------------------------------
        - Instead of scanning all intervals each time (O(n*K)),
          we use a max-heap to efficiently pick the current largest section.
        - Steps:
          1. Initially, push all intervals [stations[i], stations[i+1]] into a max-heap.
             Each entry stores {current section length, index}.
          2. For each new gas station (K times):
              * Pop the largest interval from the heap.
              * Add a gas station in that interval (increment howMany[index]).
              * Compute the new maximum section length for that interval:
                    newLength = (stations[i+1] - stations[i]) / (howMany[i] + 1)
              * Push it back into the heap.
          3. After all K stations are added, the answer is the top of the heap 
             (largest remaining section).

        Example:
        --------
        stations = [1, 13], K = 2
        Initial: interval = 12
        Place 1st station → sections = {6, 6}
        Place 2nd station → sections = {3, 3, 6}
        Heap max = 6 → result = 6

        Time Complexity:
        ----------------
        - Each station placement → O(log(n)) (heap push/pop).
        - Done K times → O(K log n).

        Space Complexity:
        -----------------
        - Heap stores O(n) intervals.
        - Extra array howMany of size (n-1).
        - O(n).
    */

    double minMaxDist(vector<int> &stations, int K) {
        int n = stations.size();
        if (n == 1) return 0; // No interval possible with 1 station

        // Max-heap: {sectionLength, index}
        priority_queue<pair<long double, int>> pq;

        // Push initial intervals
        for (int i = 0; i < n - 1; i++) {
            long double diff = stations[i + 1] - stations[i];
            pq.push({diff, i});
        }

        // howMany[i] = number of new stations placed in interval i
        vector<int> howMany(n - 1, 0);

        // Place K stations
        for (int gasStation = 1; gasStation <= K; gasStation++) {
            auto it = pq.top();
            pq.pop();

            int sectionId = it.second;
            howMany[sectionId]++;

            long double diff = stations[sectionId + 1] - stations[sectionId];
            long double sectionLength = diff / (long double)(howMany[sectionId] + 1);

            pq.push({sectionLength, sectionId});
        }

        // The maximum minimized distance is at the top of the heap
        return pq.top().first;
    }
};
