/*

You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each 
job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and 
only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

    The maximum number of jobs that can be completed within their deadlines.
    The total maximum profit earned by completing those jobs.

Examples :

Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).

Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).

*/

class Solution {
  public:
    /*
    Problem:
    ----------
    Given 'n' jobs with deadlines and profits. Each job takes 1 unit time.
    Only one job can be scheduled at a time.
    The task is to schedule jobs to maximize total profit 
    and return:
      - number of jobs done 
      - total profit earned

    Approach (Greedy + Sorting):
    ------------------------------
    1. Create a job structure with:
       - deadline (d)
       - profit (p)
       - job ID (original index)
    2. Sort jobs in descending order of profit.
    3. Create a hash array (size = max deadline + 1) initialized with -1
       → indicates available time slots for jobs
    4. Iterate over sorted jobs:
       - For each job, find its latest possible available slot from its deadline down to 1.
       - If an empty slot is found, assign the job's ID to that slot.
    5. Finally, count how many jobs were scheduled and total profit from selected jobs.

    Time Complexity:
    -----------------
    O(N log N + N * M)
    - O(N log N) for sorting N jobs
    - O(N * M) for scheduling each job in worst case (M = max deadline)

    Space Complexity:
    -----------------
    O(M)
    - M = max deadline (for hash array)

    */

    // Job structure
    struct job {
        int d;   // deadline
        int p;   // profit
        int id;  // job index
    };

    // Comparator to sort jobs in descending order of profit
    static bool comp(struct job &a, job &b) {
        return a.p > b.p;
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        struct job j[n];
        int maxi = -1;

        // Prepare job array and find maximum deadline
        for(int i = 0; i < n; i++) {
            j[i].d = deadline[i];
            j[i].p = profit[i];
            j[i].id = i;
            maxi = max(maxi, deadline[i]);
        }

        // Sort jobs by profit (highest first)
        sort(j, j + n, comp);

        // Initialize time slots for jobs (-1 means free slot)
        vector<int> hash(maxi + 1, -1);

        // Schedule jobs
        for(auto it : j) {
            // Find latest available time slot from its deadline down to 1
            for(int i = it.d; i >= 1; i--) {
                if(hash[i] == -1) {
                    hash[i] = it.id;  // assign job ID to time slot
                    break;
                }
            }
        }

        int cnt = 0;   // number of jobs done
        int prof = 0;  // total profit

        // Calculate total jobs done and profit from scheduled jobs
        for(int i = 1; i <= maxi; i++) {
            if(hash[i] != -1) {
                cnt++;
                prof += profit[hash[i]];
            }
        }

        // Return result
        vector<int> ans;
        ans.push_back(cnt);
        ans.push_back(prof);
        return ans;
    }
};
