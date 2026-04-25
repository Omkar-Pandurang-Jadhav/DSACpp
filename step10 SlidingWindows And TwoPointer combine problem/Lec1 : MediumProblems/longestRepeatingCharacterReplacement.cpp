/*You are given a string s and an integer k. You can choose any character of 
the string and change it to any other uppercase English character. You can 
perform this operation at most k times.

Return the length of the longest substring containing the same letter you can
 get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.*/

/*
============================================================
LONGEST REPEATING CHARACTER REPLACEMENT (4 APPROACHES)
============================================================

PROBLEM:
Replace at most k characters to make the longest substring
consisting of the same character.

Key formula:
change = window_size - max_frequency_in_window

============================================================


------------------------------------------------------------
1️⃣ BRUTE FORCE (Nested loops)
------------------------------------------------------------

APPROACH:
- Fix i
- Expand j
- Maintain freq array
- Track max frequency in window
- Check if replacements ≤ k

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2 * 26)

------------------------------------------------------------

SPACE COMPLEXITY:
O(26) ≈ O(1)

------------------------------------------------------------
*/

class Solution {
public:
    int characterReplacement(string s, int k) {

        if(s.size() <= 1) return s.size();

        int maxlen = 0;

        for(int i = 0; i < s.size(); i++){

            vector<int> hash(26, 0);
            int maxChange = 0;

            for(int j = i; j < s.size(); j++){

                hash[s[j] - 'A']++;

                maxChange = max(maxChange, hash[s[j] - 'A']);

                int change = (j - i + 1) - maxChange;

                if(change <= k)
                    maxlen = max(maxlen, j - i + 1);
                else break;
            }
        }

        return maxlen;
    }
};



/*
------------------------------------------------------------
2️⃣ SLIDING WINDOW (Map - Relaxed IF)
------------------------------------------------------------

APPROACH:
- Use map to store frequency
- Expand r
- Shrink once if invalid
- Window may be temporarily invalid

------------------------------------------------------------

TIME COMPLEXITY:
O(2n * log26)

------------------------------------------------------------

SPACE COMPLEXITY:
O(26)

------------------------------------------------------------
*/

class Solution {
public:
    int characterReplacement(string s, int k) {

        if(s.size() <= 1) return s.size();

        int maxlen = 0;
        int l = 0, r = 0;
        int maxChange = 0;

        map<int,int> mpp;

        while(r < s.size()){

            mpp[s[r]]++;

            maxChange = max(maxChange, mpp[s[r]]);

            int change = r - l + 1 - maxChange;

            if(change > k){
                mpp[s[l]]--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};



/*
------------------------------------------------------------
3️⃣ SLIDING WINDOW (Array - Relaxed IF)
------------------------------------------------------------

APPROACH:
- Same as above but using array instead of map
- Faster constant time operations

------------------------------------------------------------

TIME COMPLEXITY:
O(2n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(26)

------------------------------------------------------------
*/

class Solution {
public:
    int characterReplacement(string s, int k) {

        if(s.size() <= 1) return s.size();

        int maxlen = 0;
        int l = 0, r = 0;
        int maxEle = 0;

        vector<int> hash(26, 0);

        while(r < s.size()){

            hash[s[r] - 'A']++;

            maxEle = max(maxEle, hash[s[r] - 'A']);

            int change = r - l + 1 - maxEle;

            if(change > k){
                hash[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};



/*
------------------------------------------------------------
4️⃣ SLIDING WINDOW (ARRAY - CLEAN OPTIMIZED VERSION ⭐)
------------------------------------------------------------

APPROACH:
- Remove extra variable (change)
- Use direct formula in while loop
- Standard and most preferred solution

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(26)

------------------------------------------------------------

KEY INSIGHT:
- maxFreq is NOT reduced when shrinking
- Still gives correct answer (important trick)

------------------------------------------------------------
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size()==0 || s.size()==1) return s.size();
        int maxlen=0;
        int l=0;
        int r=0;
        int maxEle=0;
        int change=0;
        vector<int>hash(26,0);
        while(r<s.size()){
            
            hash[s[r]-'A']+=1;
            maxEle=max(maxEle,hash[s[r]-'A']);
            change=r-l+1-maxEle;
            if(change>k){
                hash[s[l]-'A']-=1;
                l+=1;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};

/*
============================================================
FINAL COMPARISON
============================================================

| Approach        | Time Complexity   | Space |
|----------------|------------------|-------|
| Brute Force    | O(n^2 * 26) ❌   | O(1)  |
| SW (Map)       | O(2n * log26)    | O(1)  |
| SW (Array IF)  | O(2n)            | O(1)  |
| SW (Optimized) | O(n) ⭐          | O(1)  |

============================================================
*/