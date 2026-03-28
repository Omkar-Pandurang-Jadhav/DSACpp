/*

Geek is a software engineer. He is assigned with the task of calculating average waiting time of all the processes by following shortest 
job first policy.

The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution 
time to execute next.

Given an array of integers bt of size n. Array bt denotes the burst time of each process. Calculate the average waiting time of all 
the processes and return the nearest integer which is smaller or equal to the output.

Note: Consider all process are available at time 0.

Example 1:

Input:
n = 5
bt = [4,3,7,1,2]
Output: 4
Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 4.

Example 2:

Input:
n = 4
arr = [1,2,3,4]
Output: 2
Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 2.
*/

class Solution {
  public:
    /*
    Problem:
    -----------
    Given burst times of N processes, 
    compute the average waiting time if scheduled using 
    Shortest Job First (SJF — Non-Preemptive) scheduling.

    Approach (Greedy):
    --------------------
    1. Sort the burst times in ascending order.
       (Shortest job first)
    2. Initialize:
       - `t = 0` → total time elapsed so far
       - `wt = 0` → total waiting time accumulated
    3. For each process (after sorting):
       - Add current total time `t` to waiting time
       - Update total time `t += bt[i]`
    4. Compute average waiting time as total waiting time divided by number of processes.

    Time Complexity:
    -----------------
    O(N log N)
    - Sorting burst times

    Space Complexity:
    -----------------
    O(1)
    - Only using a few variables.

    */

    long long solve(vector<int>& bt) {
        // Sort burst times (shortest job first)
        sort(bt.begin(), bt.end());
        
        int n = bt.size();
        int t = 0;      // time elapsed
        long long wt = 0;  // total waiting time

        // Calculate waiting time for each process
        for(int i = 0; i < n; i++){
            wt += t;        // add current total time to waiting time
            t += bt[i];     // increment time by current process's burst time
        }

        // Calculate average waiting time
        long long avg_wt = wt / n;

        return avg_wt;
    }
};
