/*
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) 
that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.

Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".

Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.

*/

class Solution {
public:
    string largestOddNumber(string num) {
        /*
        Problem:
        --------
        Given a numeric string, return the largest odd number 
        that can be formed by removing some (or zero) digits from the end.
        If no odd number exists, return "".

        Approach:
        ---------
        - Check the last digit:
            * If it's odd, the whole string is already the largest odd number → return it.
        - Otherwise, scan from right to left:
            * Find the rightmost odd digit.
            * Return substring from index 0 up to that digit (inclusive).
        - If no odd digit exists, return "".

        Example:
        --------
        num = "35420"
        - Last digit = 0 → even
        - Scan from right:
            '2' → even
            '4' → even
            '5' → odd at index 1
        → return num.substr(0, 2) = "35"

        Time Complexity: O(n)
            - At most one scan of the string.
        Space Complexity: O(1)
            - Only variables for indices and digits, 
              final substring reuses the original string.
        */

        int n = num.size();

        // If last digit is odd, whole string is valid
        if ((num[n - 1] - '0') % 2 == 1) 
            return num;

        // Otherwise, find rightmost odd digit
        for (int i = n - 1; i >= 0; i--) {
            char ch = num[i];
            int digit = ch - '0';
            if (digit % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }

        // No odd digit found
        return "";
    }
};
