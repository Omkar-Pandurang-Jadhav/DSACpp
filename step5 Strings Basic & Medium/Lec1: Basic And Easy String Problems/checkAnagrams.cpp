/*Given two strings s and t, return true if t is an

of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.
*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
        Problem:
        --------
        Check if string `t` is an anagram of string `s`.
        - Two strings are anagrams if they contain the same characters
          with the same frequency.

        Approach:
        ---------
        1. If the lengths of s and t are different, return false immediately.
        2. Initialize a hash array of size 26 (for lowercase letters a-z).
        3. Traverse both strings simultaneously:
            - Increment hash[s[i]-'a'] for each character in s
            - Decrement hash[t[i]-'a'] for each character in t
        4. After traversal, if all elements in the hash array are 0, 
           strings are anagrams; otherwise, not.
           
        Example:
        --------
        s = "listen", t = "silent"
        - hash array after traversal will have all 0s → return true

        Time Complexity: O(n)
            - n = length of the strings
            - Single pass through both strings and fixed-size hash array check
        Space Complexity: O(1)
            - Hash array size is fixed at 26 (constant)
        */

        // Step 1: Check length
        if(s.size() != t.size()) return false;

        // Step 2: Initialize hash array
        vector<int> hash(26, 0);
        int n = s.size();

        // Step 3: Update hash counts
        for(int i = 0; i < n; i++){
            hash[s[i]-'a']++;  // increment for s
            hash[t[i]-'a']--;  // decrement for t
        }

        // Step 4: Check if all counts are zero
        for(int i = 0; i < 26; i++){
            if(hash[i] != 0) return false;
        }

        return true; // strings are anagrams
    }
};
