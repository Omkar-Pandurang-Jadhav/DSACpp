
/*Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.

Examples:

Input: mat[][] = [[1, 3, 5], 
                [2, 6, 9], 
                [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.

Input: mat[][] = [[2, 4, 9],
                [3, 6, 7],
                [4, 7, 10]]
Output: 6
Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.

Input: mat = [[3], [4], [8]]
Output: 4
Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.*/

class Solution {
  public:
    // Function to find upper bound (first index where element > x) in a sorted row
    int upperBound(vector<int> &nums,int n,int x){
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > x){
                high = mid - 1;   // go left
            }
            else {
                low = mid + 1;    // go right
            }
        }
        return low; // index of first element greater than x
    }

    // Function to count how many elements are <= x across all rows
    int countLessThanEqual(vector<vector<int>> &mat,int n,int m,int x){
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += upperBound(mat[i], m, x);
        }
        return cnt;
    }

    // Function to find median of the matrix
    int median(vector<vector<int>> &mat) {
        /*
        Approach:
        1. Each row of the matrix is sorted but matrix as a whole is not fully sorted.
        2. The median of a matrix of size n*m lies between the minimum element (first column) 
           and maximum element (last column).
        3. Use Binary Search on value range [min, max]:
            - For each mid, count how many elements are <= mid using countLessThanEqual().
            - If count <= (n*m)/2, move right (low = mid + 1).
            - Else move left (high = mid - 1).
        4. The final 'low' will be the median.

        Example:
        Matrix = [ [1,3,5],
                   [2,6,9],
                   [3,6,9] ]
        Elements sorted = [1,2,3,3,5,6,6,9,9]
        Median = 5
        */

        int n = mat.size();
        int m = mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;

        // Step 1: Find global minimum and maximum (search space for binary search)
        for(int i=0;i<n;i++){
            low = min(low, mat[i][0]);       // first element of row (smallest in row)
            high = max(high, mat[i][m-1]);  // last element of row (largest in row)
        }
        
        int req = (m*n)/2; // index of median in sorted order
        // Step 2: Binary Search on value range
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(countLessThanEqual(mat, n, m, mid) <= req)
                low = mid + 1;  // mid is too small
            else
                high = mid - 1; // mid might be median or too big
        }
        return low;
    }
};

/*
Time Complexity:
    - upperBound() runs in O(log m).
    - countLessThanEqual() runs in O(n * log m).
    - Binary search on value range runs in O(log(max-min)).
    - Overall: O(n * log m * log(max-min)).

Space Complexity:
    - O(1), only a few variables used.
*/
