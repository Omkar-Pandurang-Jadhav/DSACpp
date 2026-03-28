/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters.
 No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

    Mapping 'e' to 'a'.
    Mapping 'g' to 'd'.

Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /*
        Problem:
        --------
        Two strings `s` and `t` are isomorphic if characters in `s` 
        can be replaced to get `t`, with the following conditions:
        - Each character in `s` must map to exactly one character in `t`.
        - No two characters from `s` can map to the same character in `t`.
        - The order must be preserved.

        Approach:
        ---------
        1. If the lengths of `s` and `t` differ → return false.
        2. Maintain two maps:
           - m1: mapping from s[i] → t[i].
           - m2: mapping from t[i] → s[i].
        3. Traverse both strings simultaneously:
           - If neither mapping exists, create both mappings.
           - Else, check consistency:
             * If m1[s[i]] != t[i] OR m2[t[i]] != s[i], return false.
        4. If we complete the loop, return true.

        Example:
        --------
        s = "egg", t = "add"
        e → a
        g → d
        Works → return true.

        s = "foo", t = "bar"
        f → b
        o → a (conflict because 'o' cannot map to both 'a' and 'r')
        → return false.

        Time Complexity: O(n)
            - Single pass over both strings.
        Space Complexity: O(Alphabet size)
            - At most O(256) for ASCII characters (constant space).
        */

        if(s.size()!=t.size()) return false;
        int n=s.size();
        map<char,char> m1,m2;

        for(int i=0;i<n;i++){
            if(m1[s[i]]==0 && m2[t[i]]==0){  // if not mapped yet
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
            if(m1[s[i]]!=t[i] && m2[t[i]]!=s[i]) return false; // mapping conflict
        }
        return true;
    }
};
