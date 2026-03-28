/*

Koko is given an array arr[], where each element represents a pile of bananas. She has exactly k hours to eat all the bananas.

Each hour, Koko can choose one pile and eat up to s bananas from it.

    If the pile has atleast s bananas, she eats exactly s bananas.

    If the pile has fewer than s bananas, she eats the entire pile in that hour.

Koko can only eat from one pile per hour.

Your task is to find the minimum value of s (bananas per hour) such that Koko can finish all the piles within k hours.

Examples:

Input: arr[] = [5, 10, 3], k = 4
Output: 5
Explanation: If Koko eats at the rate of 5 bananas per hour:
First pile of 5 bananas will be finished in 1 hour.
Second pile of 10 bananas will be finished in 2 hours.
Third pile of 3 bananas will be finished in 1 hours.
Therefore, Koko can finish all piles of bananas in 1 + 2 + 1 = 4 hours.

Input: arr[] = [5, 10, 15, 20], k = 7
Output: 10
Explanation: If Koko eats at the rate of 10 bananas per hour, it will take 6 hours to finish all the piles.*/



class Solution {
  public:
    /*
    Problem: Koko Eating Bananas (Binary Search on Answer)

    Approach:
    - We want the minimum eating speed (bananas per hour) such that
      Koko can finish all piles within k hours.
    - Range of possible speeds: [1, max(pile)].
    - For each mid speed, calculate total hours required:
         hours = sum( ceil(pile / mid) for pile in piles ).
    - If hours <= k, it means this speed is feasible, so we try smaller (high = mid - 1).
    - Otherwise, speed is too small, so we increase it (low = mid + 1).
    - At the end, `low` will be the minimum feasible speed.

    Time Complexity:
    - Each check (requiredHours) takes O(n).
    - Binary search runs O(log(maxPile)).
    - Overall: O(n * log(maxPile)).

    Space Complexity:
    - O(1), only constant extra space used.
    */

    // Helper function to find the maximum element in array
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    // Helper function: returns total hours needed if Koko eats at 'mid' speed
    long long requiredHours(vector<int> &piles, int mid) {
        int n = piles.size();
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (piles[i] + (long long)mid - 1) / mid; // ceil division
        }
        return cnt;
    }

    // Main function: binary search to find minimum eating speed
    int kokoEat(vector<int>& arr, int k) {
        int low = 1;
        int high = findMax(arr); // max pile = upper bound of speed

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (requiredHours(arr, mid) <= k) {
                high = mid - 1; // feasible, try smaller speed
            }
            else {
                low = mid + 1;  // not feasible, need bigger speed
            }
        }
        return low; // low is the minimum feasible eating speed
    }
};
