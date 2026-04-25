/*
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab"
 are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a 
substring.
*/

/*
============================================================
LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
2 APPROACHES
============================================================

------------------------------------------------------------
1️⃣ BRUTE FORCE (Nested Loops + Hash Array)
------------------------------------------------------------

APPROACH:
- Fix starting index i
- Expand substring using j
- Use hash array to check duplicates
- Break when duplicate found

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2)

→ Outer loop: n
→ Inner loop: up to n
→ Worst case: n * n

------------------------------------------------------------

SPACE COMPLEXITY:
O(256) ≈ O(1)

→ Hash array for ASCII characters

------------------------------------------------------------

NOTE:
- Simple but inefficient
- Checks all substrings

------------------------------------------------------------
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.size() == 0) return 0;

        int maxlen = INT_MIN;

        for(int i = 0; i < s.size(); i++){

            vector<int> hash(256, 0);

            for(int j = i; j < s.size(); j++){

                if(hash[s[j]] == 1) break;

                int temp = j - i + 1;

                maxlen = max(maxlen, temp);

                hash[s[j]]++;
            }
        }

        return maxlen;
    }
};



/*
------------------------------------------------------------
2️⃣ OPTIMAL (Sliding Window + Map)
------------------------------------------------------------

APPROACH:
- Use two pointers (l, r)
- Expand window using r
- If duplicate found:
    → move l to max(previous index + 1)
- Store last occurrence of characters

------------------------------------------------------------

TIME COMPLEXITY:
O(n log n)

→ Each character processed once
→ Map operations take log n

(If unordered_map / array used → O(n))

------------------------------------------------------------

SPACE COMPLEXITY:
O(256) ≈ O(1)

→ Stores last occurrence of characters

------------------------------------------------------------

KEY INSIGHT:
- Sliding window ensures no repeated characters
- l pointer never moves backward

------------------------------------------------------------
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0, r = 0;

        if(s.size() == 0 || s.size() == 1) return s.size();

        int maxlen = INT_MIN;

        map<int,int> mpp;

        while(r < s.size()){

            if(mpp.find(s[r]) != mpp.end()){
                l = max(l, mpp[s[r]] + 1);
            }

            mpp[s[r]] = r;

            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};



/*
============================================================
FINAL COMPARISON
============================================================

| Approach        | Time Complexity | Space Complexity |
|----------------|----------------|------------------|
| Brute Force    | O(n^2) ❌      | O(1)             |
| Sliding Window | O(n log n)     | O(1)             |
| Optimized SW   | O(n) ⭐        | O(1)             |

============================================================

BEST PRACTICE:
- Use array instead of map for O(n) time

Example:
vector<int> last(256, -1);

============================================================
*/


/*
============================================================
LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
OPTIMAL (Sliding Window + Array)
============================================================

APPROACH:
- Use two pointers (l, r) to maintain a window
- Use an array (hash) to store last index of each character
- Initialize hash with -1 (means not seen before)

------------------------------------------------------------

STEP-BY-STEP:
1. Start with l = 0, r = 0
2. For each character s[r]:
   → If already seen (hash[s[r]] != -1):
       - Move left pointer:
         l = max(l, hash[s[r]] + 1)
   → Update last seen index:
       hash[s[r]] = r
   → Update max length:
       maxlen = max(maxlen, r - l + 1)
3. Move r forward

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Each character is processed once
→ l and r move forward only (never backward)

------------------------------------------------------------

SPACE COMPLEXITY:
O(256) ≈ O(1)

→ Fixed size array for ASCII characters

------------------------------------------------------------

KEY INSIGHT:
- Store last occurrence of characters
- Ensure window always has unique characters
- l pointer never moves backward

------------------------------------------------------------

EDGE CASE:
- If string size is 0 or 1 → return size directly

------------------------------------------------------------
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0, r = 0;

        if(s.size() == 0 || s.size() == 1) return s.size();

        int maxlen = INT_MIN;

        vector<int> hash(256, -1);

        while(r < s.size()){

            // If character already seen
            if(hash[s[r]] != -1){
                l = max(l, hash[s[r]] + 1);
            }

            // Update last occurrence
            hash[s[r]] = r;

            // Update answer
            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};



/*
============================================================
COMPARISON WITH OTHER APPROACHES
============================================================

| Approach              | Time Complexity | Space Complexity |
|----------------------|----------------|------------------|
| Brute Force          | O(n^2) ❌      | O(1)             |
| Sliding Window (map) | O(n log n)     | O(1)             |
| Sliding Window (array)| O(n) ⭐       | O(1)             |

============================================================

WHY THIS IS BEST:
- No map overhead (no log n)
- Direct indexing → faster
- Clean and optimal

============================================================
*/