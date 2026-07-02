/*
Question:
The next greater element of an element x in an array is the first greater
element that appears to the right of x in the same array.

You are given two distinct integer arrays nums1 and nums2, where nums1
is a subset of nums2.

For every element in nums1, find its next greater element in nums2.
If no such element exists, return -1 for that element.

Return an array containing the next greater element for every element
of nums1.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]

Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]

Approach:
1. First compute the Next Greater Element (NGE) for every element in
   nums2 using a monotonic decreasing stack.
2. Traverse nums2 from right to left.
3. While traversing, remove all elements from the stack that are
   smaller than the current element because they can never become the
   next greater element for any element to their left.
4. After removing smaller elements:
   - If the stack becomes empty, there is no greater element on the
     right, so store -1.
   - Otherwise, the element at the top of the stack is the first
     greater element on the right.
5. Push the current element onto the stack before moving to the next
   index.
6. After computing the NGE array for nums2, store every element of
   nums2 along with its corresponding next greater element in a map.
7. Finally, traverse nums1 and directly obtain each answer from the
   map in O(log N) time.
8. Return the resulting array.

Time Complexity:
O(N + M log N)

where,
N = size of nums2
M = size of nums1

Computing the Next Greater Element takes O(N).
Building the map takes O(N).
Each lookup in the map takes O(log N).

Space Complexity:
O(N)

for the stack, Next Greater Element array, and map.
*/

class Solution {
public:

    int findIndex(vector<int> arr, int val) {

        int index = -1;

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] == val) {
                index = i;
                break;
            }
        }

        return index;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        // Monotonic decreasing stack
        stack<int> st;

        // Stores the Next Greater Element for every index of nums2
        vector<int> ans(n2);

        // Traverse nums2 from right to left
        for (int i = n2 - 1; i >= 0; i--) {

            // Remove all smaller elements
            while (!st.empty() && nums2[i] > st.top())
                st.pop();

            // No greater element exists
            if (st.empty())
                ans[i] = -1;

            // Stack top is the next greater element
            else
                ans[i] = st.top();

            // Push current element for future comparisons
            st.push(nums2[i]);
        }

        // Maps each element to its next greater element
        map<int, int> mpp;

        for (int i = 0; i < n2; i++) {
            mpp[nums2[i]] = ans[i];
        }

        // Stores the final answer
        vector<int> a;

        // Retrieve answers for every element of nums1
        for (int i = 0; i < n1; i++) {
            a.push_back(mpp[nums1[i]]);
        }

        return a;
    }
};