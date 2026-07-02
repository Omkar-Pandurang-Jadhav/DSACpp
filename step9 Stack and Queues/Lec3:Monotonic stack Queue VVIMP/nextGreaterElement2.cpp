/*
Question:
Given a circular integer array nums, return the next greater element
for every element in the array.

The array is circular, meaning the element after the last index is the
first element of the array.

The next greater element of an element is the first greater element
encountered while traversing towards the right in circular order.
If no greater element exists, return -1 for that element.

Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]

Explanation:
For the last element (1), we continue searching from the beginning
of the array and find 2.

Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

Approach:
1. Since the array is circular, duplicate the original array by
   appending it to itself.
2. This converts the circular traversal into a normal linear traversal,
   allowing every element to see all elements that appear after it in
   circular order.
3. Traverse the doubled array from right to left while maintaining a
   monotonic decreasing stack.
4. Before processing the current element, remove every element from the
   stack that is smaller than or equal to the current element because
   such elements can never become the next greater element.
5. If the stack becomes empty, no greater element exists, so store -1.
   Otherwise, the stack's top is the next greater element.
6. Push the current element onto the stack.
7. After computing the Next Greater Element for the doubled array,
   remove the last N answers because they correspond to the duplicated
   portion of the array.
8. The remaining first N values represent the required answer for the
   original circular array.

Time Complexity:
O(N)

where,
N = size of the original array.

Although the array size becomes 2N after duplication, every element is
pushed and popped from the stack at most once.

Space Complexity:
O(N)

for the doubled array, answer array, and monotonic stack.
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        // Duplicate the array to simulate circular traversal
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }

        // Stores the Next Greater Element for every position
        vector<int> ans(nums.size());

        // Monotonic decreasing stack
        stack<int> st;

        // Traverse from right to left
        for (int i = nums.size() - 1; i >= 0; i--) {

            // Remove all smaller or equal elements
            while (!st.empty() && nums[i] >= st.top())
                st.pop();

            // No greater element exists
            if (st.empty())
                ans[i] = -1;

            // Stack top is the next greater element
            else
                ans[i] = st.top();

            // Push current element
            st.push(nums[i]);
        }

        // Remove answers corresponding to the duplicated array
        for (int i = 0; i < n; i++)
            ans.pop_back();

        return ans;
    }
};


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(nums.size());
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {

            while (!st.empty() && nums[i % n] >= st.top())
                st.pop();

            if (st.empty())
                ans[i % n] = -1;
            else
                ans[i % n] = st.top();

            st.push(nums[i % n]);
        }

        return ans;
    }
};