/*You have a row of flowers, where each flower blooms after a specific day. The array arr[] represents the blooming schedule: arr[i] is the day the
 flower at position i will bloom. To create a bouquet, you need to collect k adjacent bloomed flowers. Each flower can only be used in one bouquet.

Your goal is to find the minimum number of days required to make exactly m bouquets. If it is not possible to make m 
bouquets with the given arrangement, return -1.
Examples:

Input: m = 3, k = 2, arr[] = [3, 4, 2, 7, 13, 8, 5]
Output: 8
Explanation: We need 3 bouquets and each bouquet should have 2 flowers. After day 8: [x, x, x, x, _, x, x], we can 
make first bouquet from the first 2 flowers, second bouquet from the next 2 flowers and the third bouquet from the last 2 flowers.

Input: m = 2, k = 3, arr[] = [5, 5, 5, 5, 10, 5, 5]
Output: 10
Explanation: We need 2 bouquets and each bouquet should have 3 flowers, After day 5: [x, x, x, x, _, x, x], we can make 
one bouquet of the first three flowers that bloomed, but cannot make another bouquet. After day 10: [x, x, x, x, x, x, x], 
Now we can make two bouquets, taking 3 adjacent flowers in one bouquet.

Input: m = 3, k = 2, arr[] = [1, 10, 3, 10, 2]
Output: -1
Explanation: As 3 bouquets each having 2 flowers are needed, that means we need 6 flowers. But there are only 5 flowers so it
 is impossible to get the needed bouquets therefore -1 will be returned.*/


class Solution {
  public:
    // Helper function to count how many bouquets can be made 
    // if flowers bloom in 'mid' days
    int noOfBouquets(vector<int> &arr,int k,int mid){
        int cnt = 0;   // total bouquets formed
        int j = 0;     // consecutive flowers count
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= mid){   // flower bloomed by 'mid' day
                j++;
                if(j == k){      // enough flowers to form 1 bouquet
                    cnt++;
                    j = 0;       // reset for next bouquet
                }
            }
            else {
                j = 0; // sequence broken, reset
            }
        }
        return cnt;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        /*
            Approach:
            ----------
            1. We need to form 'm' bouquets, each requiring 'k' consecutive flowers.
            2. First, check feasibility: if total flowers < m*k, return -1.
            3. Use Binary Search on the answer (min days required):
               - low = min element (earliest blooming flower).
               - high = max element (latest blooming flower).
            4. For each mid, check if we can make at least 'm' bouquets.
            5. If possible, move high = mid - 1 (try fewer days).
               Else, move low = mid + 1.
            6. Return low as the minimum number of days needed.

            Time Complexity: O(n * log(max(arr) - min(arr)))
                - Each binary search step checks entire array (O(n)).
                - Binary search range is log(max_day - min_day).

            Space Complexity: O(1)
                - Only variables used, no extra space.
        */

        int n = arr.size();
        if(n < (long long)m * k) return -1; // not enough flowers

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(noOfBouquets(arr, k, mid) < m){
                // not enough bouquets, need more days
                low = mid + 1;
            }
            else {
                // possible, try fewer days
                high = mid - 1;
            }
        }

        return low; // minimum days required
    }
};
