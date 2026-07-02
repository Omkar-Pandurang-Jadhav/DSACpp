/*
Question:
You are given an integer array arr[] and an array indices[]
containing query indices.

For every query index, determine the count of elements present
to its right that are strictly greater than arr[index].

Return an array where each element represents the answer for
the corresponding query.

Example 1:
Input:
arr = [3,4,2,7,5,8,10,6]
indices = [0,5]

Output:
[6,1]

Explanation:
For index 0 (value = 3), the greater elements on the right are
4, 7, 5, 8, 10 and 6.

For index 5 (value = 8), only 10 is greater.

Example 2:
Input:
arr = [1,2,3,4,1]
indices = [0,3]

Output:
[3,0]

Approach:
1. Traverse the array from right to left while maintaining a stack.
2. The stack stores elements that lie on the right side of the current
   element.
3. Before processing the current element, remove every element from the
   stack that is smaller than or equal to the current element because
   they cannot contribute directly to the current comparison.
4. Store all removed elements temporarily in another vector.
5. Count how many removed elements are actually greater than the
   current element.
6. The elements still present in the stack are already greater than the
   current element, so their count is simply the current stack size.
7. Therefore, the total count of greater elements on the right is:
      stack size + count of qualifying removed elements.
8. Store this value for every index.
9. Finally, answer each query using the precomputed answer array.

Time Complexity:
O(N^2)

where,
N = size of the array.

In the worst case, many elements may be moved into the temporary
vector repeatedly.

Space Complexity:
O(N)

for the stack, answer array, and temporary vector.
*/

class Solution {
public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {

        int n = arr.size();

        // Stores the count of greater elements for every index
        vector<int> ans(arr.size());

        // Stack storing elements to the right
        stack<int> st;

        // Stores temporarily removed elements
        vector<int> pop;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            int cnt = 0;

            // Remove elements smaller than or equal to current element
            while (!st.empty() && arr[i] >= st.top()) {

                int temp = st.top();
                st.pop();

                pop.push_back(temp);
            }

            // Count removed elements that are still greater
            for (int j = 0; j < pop.size(); j++) {

                if (arr[i] < pop[j])
                    cnt += 1;
            }

            // No greater element exists
            if (st.empty())
                ans[i] = 0;

            // Remaining stack elements are greater
            else
                ans[i] = st.size() + cnt;

            // Push current element
            st.push(arr[i]);
        }

        // Stores answers for the given queries
        vector<int> a(indices.size());

        for (int i = 0; i < indices.size(); i++) {
            a[i] = ans[indices[i]];
        }

        return a;
    }
};