/*
Question:
Given a non-negative integer represented as a string num and an integer k,
remove exactly k digits from the number so that the new number is the
smallest possible.

Return the resulting number as a string.

If the resulting number is empty, return "0".

Example 1:
Input:
num = "1432219", k = 3

Output:
"1219"

Explanation:
Remove digits 4, 3 and 2 to obtain the smallest possible number.

Example 2:
Input:
num = "10200", k = 1

Output:
"200"

Example 3:
Input:
num = "10", k = 2

Output:
"0"

--------------------------------------------------------------------
Intuition
--------------------------------------------------------------------

To obtain the smallest possible number, we should remove the first
digit that is larger than the digit immediately following it.

For example,

1432219

The first place where the number becomes larger is

1 4 3

Since

4 > 3

removing 4 immediately makes the number smaller than removing any
digit after it.

Similarly,

1432219

↓

132219

Again,

3 > 2

remove 3.

Continue this process until k digits have been removed.

This greedy strategy always produces the smallest possible number.

--------------------------------------------------------------------
Why does a Monotonic Increasing Stack work?
--------------------------------------------------------------------

We maintain a stack such that the digits inside it are always in
non-decreasing order.

Whenever the current digit is smaller than the stack top,

Current Digit < Stack Top

the larger digit on the stack should be removed because placing a
smaller digit earlier always produces a smaller number.

Therefore,

while

Current Digit < Stack Top

and

k > 0

pop the stack.

Then push the current digit.

If some removals are still left after processing every digit,
it means the number was already increasing.

For example,

123456

Nothing gets popped.

The best option is simply to remove the last k digits because they
are the largest digits remaining.

Finally, remove all leading zeros.

If the string becomes empty,

return "0".

--------------------------------------------------------------------
Approach
--------------------------------------------------------------------

1. Traverse the digits from left to right.
2. Maintain a monotonic increasing stack.
3. While:
      • stack is not empty,
      • current digit is smaller than stack top,
      • removals are still available,
   pop the stack.
4. Push the current digit.
5. If removals are still left, remove digits from the end.
6. Build the answer from the stack.
7. Remove leading zeros.
8. If the answer becomes empty, return "0".

--------------------------------------------------------------------
Time Complexity
--------------------------------------------------------------------

O(N)

where,
N = length of the string.

Each digit is pushed and popped at most once.

--------------------------------------------------------------------
Space Complexity
--------------------------------------------------------------------

O(N)

for the monotonic stack.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {

        if (k == num.size())
            return "0";

        stack<char> st;

        int n = num.size();

        int temp = k;

        // Push first digit
        st.push(num[0]);

        // Maintain a monotonic increasing stack
        for (int i = 1; i < n; i++) {

            while (!st.empty() &&
                   temp != 0 &&
                   num[i] < st.top()) {

                st.pop();
                temp--;
            }

            st.push(num[i]);
        }

        // Number was already increasing
        if (temp == k)
            return num.substr(0, n - k);

        // Construct the answer
        string ans = "";

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        // Remove remaining digits from the end
        if (temp != 0)
            ans = ans.substr(0, ans.size() - temp);

        // Remove leading zeros
        while (!ans.empty() && ans[0] == '0') {
            ans = ans.substr(1);
        }

        if (ans.empty())
            return "0";

        return ans;
    }
};