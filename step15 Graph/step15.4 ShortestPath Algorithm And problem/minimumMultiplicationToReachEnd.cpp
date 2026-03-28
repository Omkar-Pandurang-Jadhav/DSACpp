/*
Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in 
the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not 
possible to reach end, then return -1.

*/

// User function Template for C++

class Solution {
  public:
    // Function to find the minimum multiplications to reach 'end' from 'start'
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // Define mod value as per problem statement
        int mod = 100000;

        // Number of elements in the array
        int n = arr.size();

        // Distance array to track minimum steps to reach each number modulo mod
        vector<int> dist(mod, INT_MAX);

        // BFS queue storing pairs of {steps taken so far, current value}
        queue<pair<int,int>> q;

        // Start BFS from the initial 'start' value at step 0
        q.push({0, start});

        // Distance to reach 'start' is 0
        dist[start] = 0;

        // BFS loop runs until the queue is empty
        while(!q.empty()){
            // Get the front element from queue
            int step = q.front().first;    // Steps taken so far
            int value = q.front().second;  // Current value
            q.pop();

            // If current value matches 'end', return the number of steps taken
            if(value == end) return step;

            // Traverse all numbers in arr to multiply with current value
            for(int i=0; i<n; i++){
                // Calculate new value after multiplication and mod operation
                int v = (value * arr[i]) % mod;

                // If this new value can be reached in fewer steps than before
                if(step + 1 < dist[v]){
                    // Update distance for this value
                    dist[v] = step + 1;

                    // Push the new state into the queue with incremented step
                    q.push({step + 1, v});
                }
            }
        }

        // If 'end' cannot be reached after exhausting all possibilities
        return -1;
    }
};

/*
tc->O(mod×n)
sc->O(mod)
*/