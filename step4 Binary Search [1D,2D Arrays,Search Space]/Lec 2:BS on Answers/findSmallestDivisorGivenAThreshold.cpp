/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it,
 and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 

Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
*/

class Solution {
public:
    // Helper function to calculate the sum of divisors for a given divisor m
    int sumOfDivisor(vector<int> &arr,int m){
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            // (arr[i] + m - 1) / m  is equivalent to ceil(arr[i] / m) but faster
            sum = sum + (arr[i] + m - 1) / m;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        // Approach:
        // 1. We need to find the smallest integer divisor "d" such that
        //    sum( ceil(nums[i] / d) ) <= threshold.
        // 2. The divisor "d" lies between 1 and max(nums).
        // 3. Use Binary Search on divisor space:
        //    - If sumOfDivisor(nums, mid) <= threshold, move left (high = mid - 1).
        //    - Else move right (low = mid + 1).
        // 4. The final "ans" will be the smallest divisor satisfying the condition.

        int low = 1;
        int high = *max_element(nums.begin(), nums.end()); // maximum element as upper bound
        int ans;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(sumOfDivisor(nums, mid) <= threshold){
                ans = mid;      // mid is a valid divisor, try smaller one
                high = mid - 1;
            }
            else {
                low = mid + 1;  // mid is too small, try larger one
            }
        }
        return ans;
    }
};

/*
Time Complexity:
    - sumOfDivisor() takes O(n) for each divisor check.
    - Binary Search runs in O(log(max(nums))).
    - Overall: O(n * log(max(nums))).

Space Complexity:
    - O(1), as we only use a few extra variables.
*/
