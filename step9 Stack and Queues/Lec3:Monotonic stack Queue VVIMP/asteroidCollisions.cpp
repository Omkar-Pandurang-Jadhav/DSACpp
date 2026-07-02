/*
Question:
We are given an array asteroids where each element represents an asteroid.

The absolute value of an asteroid represents its size.
The sign of an asteroid represents its direction:
    Positive  -> Moving towards the right.
    Negative  -> Moving towards the left.

Whenever two asteroids moving towards each other collide:
1. The smaller asteroid explodes.
2. If both have the same size, both explode.
3. Asteroids moving in the same direction never collide.

Return the state of the asteroids after all collisions.

Example 1:
Input:
asteroids = [5,10,-5]

Output:
[5,10]

Example 2:
Input:
asteroids = [8,-8]

Output:
[]

Example 3:
Input:
asteroids = [10,2,-5]

Output:
[10]

Example 4:
Input:
asteroids = [3,5,-6,2,-1,4]

Output:
[-6,2,4]

--------------------------------------------------------------------
Approach:
--------------------------------------------------------------------

1. Traverse the array from right to left.
2. Maintain a stack containing the asteroids that have survived so far
   on the right side.
3. A collision is only possible when:
      - Current asteroid is moving right (positive), and
      - Top of the stack is moving left (negative).
   These are the only two asteroids moving towards each other.
4. If the current asteroid is larger than the top negative asteroid,
   destroy the smaller asteroid by repeatedly popping the stack until
   either:
      - the stack becomes empty,
      - the current asteroid becomes smaller,
      - or both asteroids become equal.
5. If both asteroids have the same size, both explode.
6. If the asteroid on the stack is larger, the current asteroid
   explodes and is discarded.
7. If no collision exists, or the current asteroid survives every
   collision, push it onto the stack.
8. Finally, pop every surviving asteroid from the stack into the
   answer vector.
   Since we traversed from right to left, popping from the stack
   automatically restores the original left-to-right order.

--------------------------------------------------------------------
Why does this work?
--------------------------------------------------------------------

While traversing from right to left, the stack stores all surviving
asteroids lying on the right side.

A collision is possible only in the following situation:

        Current Asteroid        Stack Top
              (+)                  (-)

              ----->          <-----

Both are moving towards each other.

The remaining possibilities never collide:

(+) (+)   -> Same direction

(-) (-)   -> Same direction

(-) (+)   -> Moving away from each other

Hence only one collision case needs to be handled.

--------------------------------------------------------------------
Time Complexity:
--------------------------------------------------------------------

O(N)

where,
N = number of asteroids.

Each asteroid is pushed onto the stack at most once and popped at most
once.

--------------------------------------------------------------------
Space Complexity:
--------------------------------------------------------------------

O(N)

for storing the surviving asteroids in the stack.
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n = asteroids.size();

        // Stores the surviving asteroids
        stack<int> st;

        // Push the last asteroid
        st.push(asteroids[n - 1]);

        // Traverse from right to left
        for (int i = n - 2; i >= 0; i--) {

            // Collision is possible only when
            // current asteroid is positive and
            // stack top is negative
            if (!st.empty() &&
                asteroids[i] > 0 &&
                st.top() < 0) {

                // Destroy all smaller asteroids
                while (!st.empty() &&
                       st.top() < 0 &&
                       asteroids[i] > abs(st.top())) {

                    st.pop();
                }

                // Both asteroids are equal
                if (!st.empty() &&
                    st.top() < 0 &&
                    asteroids[i] == abs(st.top())) {

                    st.pop();
                    continue;
                }

                // Current asteroid explodes
                if (!st.empty() &&
                    st.top() < 0 &&
                    asteroids[i] < abs(st.top())) {

                    continue;
                }

                // Current asteroid survives
                st.push(asteroids[i]);
            }

            // No collision is possible
            else {

                st.push(asteroids[i]);
            }
        }

        // Stores the final surviving asteroids
        vector<int> ans;

        while (!st.empty()) {

            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};