/*
Question:
You are given an integer array arr[].

For every element in the array, determine its Next Smaller Element (NSE).

The Next Smaller Element of an element is the first element that appears
to its right and is strictly smaller than the current element.

If no such element exists, return -1 for that position.

Example 1:
Input: arr = [4,8,5,2,25]
Output: [2,5,2,-1,-1]

Example 2:
Input: arr = [13,7,6,12]
Output: [7,6,-1,-1]

Example 3:
Input: arr = [4,1]
Output: [1,-1]

Approach:
1. Traverse the array from right to left because the Next Smaller
   Element always lies on the right side of the current element.
2. Maintain a monotonic increasing stack.
3. Before processing the current element, remove all elements from
   the stack that are greater than or equal to the current element.
   Such elements can never become the Next Smaller Element because
   the current element is smaller (or equal) and is closer to all
   elements on its left.
4. After removing these elements:
   - If the stack becomes empty, there is no smaller element on the
     right, so store -1.
   - Otherwise, the element at the top of the stack is the first
     smaller element on the right.
5. Push the current element onto the stack so it can serve as the
   Next Smaller Element for the elements to its left.
6. Continue until the beginning of the array.
7. Return the answer array.

Time Complexity:
O(N)

where,
N = size of the array.

Each element is pushed and popped from the stack at most once.

Space Complexity:
O(N)

for the monotonic stack and the answer array.
*/

class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {

        int n = arr.size();

        // Stores the Next Smaller Element for every index
        vector<int> ans(arr.size());

        // Monotonic increasing stack
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove all elements greater than or equal to
            // the current element
            while (!st.empty() && arr[i] <= st.top())
                st.pop();

            // No smaller element exists
            if (st.empty())
                ans[i] = -1;

            // Stack top is the Next Smaller Element
            else
                ans[i] = st.top();

            // Push the current element onto the stack
            st.push(arr[i]);
        }

        return ans;
    }
};