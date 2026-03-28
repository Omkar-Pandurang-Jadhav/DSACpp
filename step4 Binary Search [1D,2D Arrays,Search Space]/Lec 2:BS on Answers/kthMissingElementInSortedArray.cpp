/*
Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

 */

 // Brute FOrce 
 class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=1;
        int high=arr[n-1];
        for(int i=0;i<n;i++){
            if(arr[i]<=k)k++;
            else break;
        }
        
        return k;
    }
};


// Optimal Approach

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        // If kth missing number is before the first element
        if (k < arr[0]) return k;

        int low = 0, high = n - 1;

        // Binary search to find how many numbers are missing before position 'mid'
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Missing numbers until arr[mid] = arr[mid] - (mid+1)
            if ((arr[mid] - (mid + 1)) < k) 
                low = mid + 1;   // kth missing lies to the right
            else 
                high = mid - 1;  // kth missing lies to the left
        }

        // At this point, 'high' points to the last index where missing < k
        // Answer = (numbers in arr[0..high]) + (remaining missing)
        return high + 1 + k;
    }
};

/*
-----------------------------------
Approach:
-----------------------------------
1. We want to find the kth missing positive number.
2. For each arr[mid], the number of missing elements up to arr[mid] is:
      missing = arr[mid] - (mid+1)
   (because up to index mid, we "should have" mid+1 numbers if no gaps).
3. Using binary search:
   - If missing < k, it means kth missing lies to the right → move low = mid+1.
   - Else, kth missing lies to the left → move high = mid-1.
4. After binary search ends:
   - 'high' will be the last position where missing < k.
   - So the answer is (high+1 + k).

-----------------------------------
Time Complexity: O(log n)
   - Binary search on array of size n.
Space Complexity: O(1)
   - Only a few extra variables are used.
-----------------------------------
*/
