class Solution {
public:
    bool rotateString(string s, string goal) {
        /*
        Problem:
        --------
        Check if string `s` can be rotated any number of times 
        to become string `goal`.

        Approach:
        ---------
        1. Get the size of string `s` as `n`.
        2. Iterate `n` times (maximum possible rotations):
            a. Remove the last character using `pop_back()`.
            b. Insert it at the beginning using `insert(s.begin(), last)`.
            c. Check if the rotated string equals `goal` using `==`.
               - If yes, return true.
        3. If none of the rotations match `goal`, return false.

        Example:
        --------
        s = "abcde", goal = "deabc"
        Rotations:
            1: "eabcd"
            2: "deabc"  → matches goal → return true

        Time Complexity: O(n^2)
            - n rotations
            - Each insert at beginning costs O(n)
            - Each comparison `s == goal` costs O(n)
        Space Complexity: O(1)
            - Only constant extra space for `last` character
            - String `s` is modified in place
        */

        int n = s.size();

        for(int i = 0; i < n; i++){
            char last = s.back();   // get last character
            s.pop_back();           // remove last character
            s.insert(s.begin(), last); // insert it at front

            if(s == goal) return true; // check equality
        }

        return false; // no rotation matched goal
    }
};


class Solution {
public:
    bool areRotations(string &s1, string &s2) {
        /*
        Problem:
        --------
        Check if string s2 is a rotation of string s1.

        Approach:
        ---------
        1. If s2 is a rotation of s1, then s2 must be a substring of (s1 + s1).
           Example: s1 = "abcde", s2 = "deabc"
           s1+s1 = "abcdeabcde" → "deabc" is a substring → true
        2. Concatenate s1 with itself: temp = s1 + s1
        3. Use string::find() to check if s2 is a substring of temp.
        4. If found, return true; otherwise, return false.

        Example:
        --------
        s1 = "abcde", s2 = "cdeab"
        temp = "abcdeabcde"
        temp.find(s2) != string::npos → true

        Time Complexity: O(n)
            - n = length of s1 (and s2)
            - Concatenation O(n), find() is O(n) in worst case
        Space Complexity: O(n)
            - For storing temp = s1 + s1
        */

        int n = s1.size();

        // Concatenate s1 with itself
        string temp = s1 + s1;

        // Check if s2 exists in the concatenated string
        if(temp.find(s2) != string::npos) return true;

        return false; // s2 is not a rotation
    }
};
