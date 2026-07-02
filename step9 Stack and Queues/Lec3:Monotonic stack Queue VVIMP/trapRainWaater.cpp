/*
Question:
Given n non-negative integers representing the elevation map where the
width of each bar is 1, compute how much rainwater can be trapped
after raining.

Example 1:
Input:
height = [0,1,0,2,1,0,1,3,2,1,2,1]

Output:
6

Example 2:
Input:
height = [4,2,0,3,2,5]

Output:
9

Approach:
1. For every index, the amount of water that can be trapped depends on
   the tallest bar on its left and the tallest bar on its right.
2. Create a prefix maximum array where prefixMax[i] stores the maximum
   height from index 0 to i.
3. Create a suffix maximum array where suffixMax[i] stores the maximum
   height from index i to the last index.
4. For every index:
      Water Level = min(prefixMax[i], suffixMax[i])
   because water cannot rise above the shorter boundary.
5. Water trapped at the current index is:
      Water Level - height[i]
6. Sum the trapped water for every index and return the total.

Why does this work?

Suppose the current bar has height:

        height[i]

The tallest wall on its left is:

        prefixMax[i]

The tallest wall on its right is:

        suffixMax[i]

Water can only be stored if both boundaries exist.

The highest possible water level is limited by the shorter boundary.

Therefore,

        Water Level = min(prefixMax[i], suffixMax[i])

Hence,

        Water Trapped = Water Level - height[i]

If the current bar itself is the tallest boundary, the above
expression naturally becomes zero.

Time Complexity:
O(N)

where,
N = size of the array.

Three linear traversals are performed.

Space Complexity:
O(N)

for storing the prefix maximum and suffix maximum arrays.
*/

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        // Stores the maximum height from the left
        vector<int> prefixMax(n);

        // Stores the maximum height from the right
        vector<int> suffixMax(n);

        // First element itself is the maximum from the left
        prefixMax[0] = height[0];

        // Last element itself is the maximum from the right
        suffixMax[n - 1] = height[n - 1];

        // Compute prefix maximum array
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(height[i], prefixMax[i - 1]);
        }

        // Compute suffix maximum array
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(height[i], suffixMax[i + 1]);
        }

        // Stores the total trapped water
        int total = 0;

        // Calculate water trapped at every index
        for (int i = 0; i < n; i++) {

            total += min(prefixMax[i], suffixMax[i]) - height[i];
        }

        return total;
    }
};



/*
Question:
Given n non-negative integers representing an elevation map where the
width of each bar is 1, compute how much rainwater can be trapped
after raining.

Example 1:
Input:
height = [0,1,0,2,1,0,1,3,2,1,2,1]

Output:
6

Example 2:
Input:
height = [4,2,0,3,2,5]

Output:
9

Approach:
1. Maintain a monotonic decreasing stack that stores the indices of
   the elevation bars.
2. Traverse the array from left to right.
3. If the current bar is smaller than or equal to the bar at the top
   of the stack, simply push its index onto the stack.
4. Otherwise, the current bar acts as a right boundary for one or more
   valleys.
5. Repeatedly pop the stack until either:
   - the stack becomes empty, or
   - the current bar is no longer taller than the stack's top.
6. The popped bar represents the bottom of the trapped water.
7. After popping:
   - The new stack top becomes the left boundary.
   - The current index becomes the right boundary.
8. The width of trapped water is:

      right - left - 1

9. The height of trapped water is:

      min(height[left], height[right]) - height[bottom]

10. Water trapped for the current valley is:

      width × height

11. Add this value to the total answer.
12. Push the current index onto the stack.
13. Continue until all bars are processed.

Why does this work?

Whenever a taller bar is encountered, it closes one or more valleys.

For every popped element:

- Left Boundary  -> stack.top()
- Bottom         -> popped element
- Right Boundary -> current index

The water level is limited by the smaller of the two boundaries.

Hence,

Water Height =
min(Left Boundary Height, Right Boundary Height)
- Bottom Height

The trapped water occupies every bar lying strictly between the
two boundaries.

Therefore,

Width = right - left - 1

and

Water = Width × Height

Time Complexity:
O(N)

where,
N = size of the array.

Every index is pushed onto the stack once and popped at most once.

Space Complexity:
O(N)

for storing the indices in the monotonic stack.
*/

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        // Monotonic decreasing stack storing indices
        stack<int> st;

        st.push(0);

        // Stores the total trapped water
        int total = 0;

        int bottom;
        int left;
        int right;
        int width;
        int h;

        // Traverse the elevation map
        for (int i = 1; i < n; i++) {

            // Current bar forms the right boundary
            while (!st.empty() && height[i] > height[st.top()]) {

                // Height of the valley bottom
                bottom = height[st.top()];

                st.pop();

                // No left boundary exists
                if (st.empty())
                    continue;

                // Left boundary index
                left = st.top();

                // Right boundary index
                right = i;

                // Width of trapped water
                width = right - left - 1;

                // Height of trapped water
                h = min(height[left], height[right]) - bottom;

                // Add trapped water
                total += h * width;
            }

            // Push current index
            st.push(i);
        }

        return total;
    }
};