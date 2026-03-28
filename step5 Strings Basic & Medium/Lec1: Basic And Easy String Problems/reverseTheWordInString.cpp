/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a 
single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

class Solution {
public:
    string reverseWords(string s) {
        /*
        Approach:
        ----------
        - Task: Reverse the order of words in a string while trimming spaces.
          Example: "the sky is blue" -> "blue is sky the"

        Steps:
        1. Reverse the entire string -> words come in reversed order.
        2. Traverse the reversed string:
            - Build each word until we hit a space.
            - Reverse each word individually to restore its original order.
            - Append it to the answer string with a single space separator.
        3. Skip empty words (handles multiple spaces).
        
        Example Walkthrough:
        Input:  "the sky is blue"
        Step1:  "eulb si yks eht"
        Step2:  word="blue" → ans="blue"
                word="is"   → ans="blue is"
                word="sky"  → ans="blue is sky"
                word="the"  → ans="blue is sky the"

        Time Complexity: O(n), where n = length of string
            - One full traversal for reverse
            - One full traversal to build words
        Space Complexity: O(n)
            - For answer string and temporary word
            - O(1) extra auxiliary space
        */

        int n = s.size();
        string ans = "";

        // Step 1: reverse the whole string
        reverse(s.begin(), s.end());

        // Step 2: process each word
        for (int i = 0; i < n; i++) {
            string word = "";

            // Collect a word until space
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Reverse the word back to correct order
            reverse(word.begin(), word.end());

            // Append if not empty (handles multiple spaces)
            if (ans.length() > 0 && word.length() != 0) {
                ans += " " + word;
            } else {
                ans += word;
            }
        }
        return ans;
    }
};
