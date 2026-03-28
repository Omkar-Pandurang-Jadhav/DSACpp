/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/


class Solution {
public:
    // Helper function to find the Longest Common Prefix (LCP) of two strings
    string lcp(string s1, string s2){
        /*
        Approach for lcp:
        -----------------
        1. Ensure s1 is the shorter string (to avoid out-of-bound access).
        2. Compare characters one by one.
        3. Return the substring up to the first mismatch.
        4. If all characters match, return s1 (the shorter string).

        Time Complexity: O(min(n1, n2)) for strings of lengths n1 and n2
        Space Complexity: O(min(n1, n2)) due to temporary substring created
        */
        int n1 = s1.size();
        int n2 = s2.size();

        // Swap if s1 is longer
        if(n1 > n2) return lcp(s2, s1);

        for(int i = 0; i < n1; i++){
            if(s1[i] != s2[i]){
                return s1.substr(0, i);  // substring up to mismatch
            }
        }

        return s1;  // all characters match
    }

    string longestCommonPrefix(vector<string>& strs) {
        /*
        Approach for longestCommonPrefix:
        ---------------------------------
        1. Iterate through the vector of strings.
        2. Update each next string with the LCP of itself and the previous string.
           - After processing, the last string will contain the LCP of all strings.
        3. Return the last string as the answer.

        Time Complexity: O(N * M)
            - N = number of strings
            - M = length of the smallest string
            - Each lcp() call takes O(M) and is called N-1 times.
        Space Complexity: O(M)
            - Temporary strings created in lcp()
            - Recursive call adds minor overhead but depth is at most 1
        */
        int n = strs.size();
        for(int i = 0; i < n-1; i++){
            strs[i+1] = lcp(strs[i], strs[i+1]);  // update with LCP so far
        }
        return strs[n-1];  // final LCP
    }
};
