/*
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. 
You also have an integer k representing the number of students. The task is to allocate books to each student such that:

    Each student receives atleast one book.
    Each student is assigned a contiguous sequence of books.
    No book is assigned to more than one student.

The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations,
 find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1.

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.

Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.*/


// Brute  Force

class Solution {
  public:
    // Function to count how many students are required 
    // if each student is allowed 'pages' maximum
    int countStudents(vector<int> &arr,int pages){
        int stu=1;           // at least one student required
        int pageCount=0;     // current pages allocated
        for(int i=0;i<arr.size();i++){
            if(pageCount+arr[i] <= pages){
                // allocate to current student
                pageCount += arr[i];
            }
            else{
                // allocate to next student
                stu++;
                pageCount = arr[i];
            }
        }
        return stu;
    }

    // Main function to find minimum number of pages
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(n < k) return -1;     // if students are more than books

        int sum = 0;
        int max = INT_MIN;
        for(int i=0;i<n;i++){
            if(max < arr[i]) max = arr[i];   // maximum element
            sum += arr[i];                   // total sum
        }

        int low = max;   // lower bound = max element
        int high = sum;  // upper bound = total sum

        for(int i=low;i<=high;i++){
            int cnt = countStudents(arr,i);
            if(cnt <= k) return i;   // ✅ condition fixed (<= k instead of == k)
        }
        return -1;
    }
};


// Optimal


class Solution {
  public:
    // Function to count how many students are required 
    // if each student is allowed 'pages' maximum
    int countStudents(vector<int> &arr,int pages){
        int stu=1;           // at least one student required
        int pageCount=0;     // current pages allocated
        for(int i=0;i<arr.size();i++){
            if(pageCount + arr[i] <= pages){
                // allocate to current student
                pageCount += arr[i];
            }
            else{
                // allocate to next student
                stu++;
                pageCount = arr[i];
            }
        }
        return stu;
    }

    // Main function to find minimum number of pages
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(n < k) return -1;     // if students are more than books

        int sum = 0;
        int max = INT_MIN;
        for(int i=0;i<n;i++){
            if(max < arr[i]) max = arr[i];   // maximum element
            sum += arr[i];                   // total sum
        }

        int low = max;   // lower bound = max element
        int high = sum;  // upper bound = total sum
        int ans = -1;

        // binary search on answer
        while(low <= high){
            int mid = low + (high - low) / 2;
            int cnt = countStudents(arr, mid);

            if(cnt > k){
                // more students needed → increase pages
                low = mid + 1;
            }
            else{
                // valid allocation → try smaller value
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};

/*
Approach:
-----------
1. Each student must get a contiguous sequence of books.
2. The minimum possible max pages = max(arr) (since at least one book must be allocated).
3. The maximum possible max pages = sum(arr) (if one student takes all books).
4. Use binary search between [max, sum]:
   - For a mid value, check how many students are required using countStudents().
   - If students > k → not possible, increase low.
   - Else possible, store answer and try smaller high.
5. The first valid minimum value is our answer.

Time Complexity:
-----------------
- countStudents() runs in O(n).
- Binary search runs for log(sum - max) iterations.
- Total = O(n * log(sum)).

Space Complexity:
-----------------
- O(1), only variables used.
*/
