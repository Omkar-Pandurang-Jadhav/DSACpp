/*A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with 
packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts
 like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
*/

class Solution {
public:
    // Function to check how many days are required if ship capacity = mid
    int requiredDays(vector<int> &arr,int mid){
        int cnt = 1;       // at least 1 day required
        int weight = 0;
        for(int i=0; i<arr.size(); i++){
            if(weight + arr[i] <= mid){
                // add current package to the same day
                weight += arr[i];
            }
            else {
                // need a new day since capacity exceeded
                cnt++;
                weight = arr[i];
            }
        }
        return cnt;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        // Search space for binary search:
        // minimum capacity = maximum element (must fit the heaviest package)
        // maximum capacity = sum of all weights (all in 1 day)
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        // Binary search to find minimum feasible ship capacity
        while(low <= high){
            int mid = low + (high - low)/2;

            // check required days with capacity = mid
            if(requiredDays(weights, mid) > days){
                // capacity too small → increase it
                low = mid + 1;
            }
            else {
                // capacity is valid → try smaller one
                high = mid - 1;
            }
        }

        // low is the minimum capacity needed
        return low;
    }
};

/*
Approach:
1. Use Binary Search on Answer (ship capacity).
2. Range of answer:
   - low = max(weights)  → at least largest package must fit.
   - high = sum(weights) → ship all packages in one day.
3. For each mid (capacity guess), compute days required using a greedy approach.
4. If days > allowed, increase capacity (low = mid+1).
5. Else reduce capacity (high = mid-1).
6. Final answer = low (minimum feasible capacity).

Time Complexity:
- requiredDays() = O(n)
- Binary search iterations = O(log(sum(weights) - max(weights)))
- Total = O(n * log(sum(weights) - max(weights)))

Space Complexity:
- O(1) extra space (ignoring input storage).
*/
