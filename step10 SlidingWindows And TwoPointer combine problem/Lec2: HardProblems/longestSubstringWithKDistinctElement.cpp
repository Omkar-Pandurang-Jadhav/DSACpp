
/*
You are given a string s consisting only lowercase alphabets and an integer k.
 Your task is to find the length of the longest substring that contains exactly 
 k distinct characters.

Note : If no such substring exists, return -1. 

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", 
which includes 'c', 'b', and 'e'.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b',
 making it the longest valid substring.*/

/*
============================================================
LONGEST SUBSTRING WITH EXACTLY K DISTINCT CHARACTERS
(2 APPROACHES)
============================================================

PROBLEM:
Find the length of the longest substring that contains
exactly k distinct characters.

If no such substring exists → return -1

============================================================


------------------------------------------------------------
1️⃣ BRUTE FORCE (SET + NESTED LOOPS)
------------------------------------------------------------

APPROACH:
- Fix starting index i
- Expand substring using j
- Use set to track distinct characters
- If set size == k → update maxlen
- If set size > k → break

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2 * log k)

→ Outer loop: n
→ Inner loop: n
→ set insert: log k

------------------------------------------------------------

SPACE COMPLEXITY:
O(k)

------------------------------------------------------------
*/

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int maxlen=-1;
        for(int i=0;i<s.size();i++){
            set<char> st;
            for(int j=i;j<s.size();j++){
                st.insert(s[j]);
                if(st.size()==k) maxlen=max(maxlen,j-i+1);
                else if(st.size()>k) break;
            }
        }
        return maxlen;
    }
};



/*
------------------------------------------------------------
2️⃣ SLIDING WINDOW (OPTIMAL ⭐)
------------------------------------------------------------

APPROACH:
- Use two pointers (l, r)
- Use map to store frequency
- Expand window using r
- If distinct > k → shrink window using l
- If distinct == k → update maxlen

------------------------------------------------------------

TIME COMPLEXITY:
O(2n * log k)

→ r moves n times
→ l moves at most n times
→ map operations: log k

------------------------------------------------------------

SPACE COMPLEXITY:
O(k)

------------------------------------------------------------

KEY INSIGHT:
- Maintain window with at most k distinct characters
- Only update answer when exactly k

------------------------------------------------------------
*/

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int maxlen=-1;
        map<char,int> mpp;
        int l=0;
        int r=0;

        while(r<s.size()){

            mpp[s[r]]+=1;

            // shrink window
            while(mpp.size()>k){
                mpp[s[l]]-=1;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l+=1;
            }

            // valid window
            if(mpp.size()==k)
                maxlen=max(maxlen,r-l+1);

            r+=1;
        }

        return maxlen;
    }
};



/*
============================================================
FINAL COMPARISON
============================================================

| Approach        | Time Complexity      | Space |
|----------------|---------------------|-------|
| Brute Force    | O(n^2 * log k) ❌   | O(k)  |
| Sliding Window | O(2n * log k) ⭐    | O(k)  |

============================================================

IMPORTANT:
- Exactly k → update only when size == k
- At most k → different problem

============================================================
*/