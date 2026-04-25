/*
Given two strings s and t of lengths m and n respectively, return the minimum 
window substring of s such that every character in t (including duplicates) is 
included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from
 string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only ha*/

/*
============================================================
MINIMUM WINDOW SUBSTRING (2 APPROACHES)
============================================================

PROBLEM:
Find the smallest substring in s that contains all
characters of t (including frequency).

If no such substring exists → return ""

============================================================


------------------------------------------------------------
1️⃣ BRUTE FORCE
------------------------------------------------------------

APPROACH:
- Fix starting index i
- Expand j
- Maintain frequency of t
- Decrease count when matching chars found
- When all characters matched → update answer

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2 * 256) ≈ O(n^2)

→ Outer loop: n
→ Inner loop: n
→ Hash operations constant

------------------------------------------------------------

SPACE COMPLEXITY:
O(256) ≈ O(1)

------------------------------------------------------------
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        int n=s.size();
        int m=t.size();
        int minlen=INT_MAX;
        int ind=0;

        for(int i=0;i<n;i++){
            vector<int> hash(256,0);
            int cnt=0;

            for(int k=0;k<m;k++){
                hash[t[k]]+=1;
            }

            for(int j=i;j<n;j++){
                if(hash[s[j]]>0){
                    hash[s[j]]-=1;
                    cnt+=1;
                }

                if(cnt==t.size()){
                    if(j-i+1<minlen){
                        minlen=j-i+1;
                        ind=i;
                        break;
                    }
                }
            }
        }

        if(minlen==INT_MAX) return "";

        return s.substr(ind,minlen);
    }
};



/*
------------------------------------------------------------
2️⃣ SLIDING WINDOW (OPTIMAL ⭐)
------------------------------------------------------------

APPROACH:
- Use two pointers (l, r)
- Maintain frequency array of t
- Expand r:
    → decrease count if useful char
- When all chars matched (cnt == t.size()):
    → shrink from left to minimize window

------------------------------------------------------------

TIME COMPLEXITY:
O(2n) → O(n)

→ r moves n times
→ l moves at most n times

------------------------------------------------------------

SPACE COMPLEXITY:
O(256) ≈ O(1)

------------------------------------------------------------

KEY INSIGHT:
- cnt tracks how many characters of t are matched
- We shrink only when valid window is formed
- Hash may contain negative values (extra chars)

------------------------------------------------------------
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";

        int n=s.size();
        int m=t.size();

        int minlen=INT_MAX;
        int ind=0;

        int l=0, r=0;

        vector<int> hash(256,0);

        // store frequency of t
        for(int i=0;i<t.size();i++){
            hash[t[i]]+=1;
        }

        int cnt=0;

        while(r<s.size()){

            // if character is needed
            if(hash[s[r]]>0) cnt+=1;

            hash[s[r]]-=1;

            // valid window
            while(cnt==t.size()){

                if(r-l+1<minlen){
                    minlen=r-l+1;
                    ind=l;
                }

                // shrink window
                hash[s[l]]+=1;

                if(hash[s[l]]>0) cnt-=1;

                l+=1;
            }

            r+=1;
        }

        if(minlen==INT_MAX) return "";

        return s.substr(ind,minlen);
    }
};



/*
============================================================
FINAL COMPARISON
============================================================

| Approach        | Time Complexity | Space |
|----------------|----------------|-------|
| Brute Force    | O(n^2) ❌      | O(1)  |
| Sliding Window | O(n) ⭐        | O(1)  |

============================================================

IMPORTANT INSIGHT:
- Sliding window maintains validity incrementally
- No need to recompute frequency every time
- Negative values in hash mean extra characters

============================================================
*/