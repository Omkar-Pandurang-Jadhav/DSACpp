/*
ou are given a string s consisting of lowercase characters and an integer k,
 You have to count all possible substrings that have exactly k distinct characters.

Examples :

Input: s = "abc", k = 2
Output: 2
Explanation: Possible substrings are ["ab", "bc"]
Input: s = "aba", k = 2
Output: 3
Explanation: Possible substrings are ["ab", "ba", "aba"]
Input: s = "aa", k = 1
Output: 3
Explanation: Possible substrings are ["a", "a", "aa"]
*/



/*
============================================================
COUNT SUBSTRINGS WITH EXACTLY K DISTINCT CHARACTERS
============================================================

APPROACH:
- Use Sliding Window + At Most Trick
- Count substrings with at most k distinct characters
- Count substrings with at most (k-1) distinct characters
- Subtract:

    exactly k = atMost(k) - atMost(k-1)

------------------------------------------------------------

FUNCTION (atMost k):
- Use two pointers (l, r)
- Expand r and add character to map
- If distinct characters > k → shrink from left
- For each valid window, add (r - l + 1) to count

------------------------------------------------------------

TIME COMPLEXITY:
O(2n * log k) ≈ O(n log k)

→ r moves n times
→ l moves at most n times
→ map operations take O(log k)

------------------------------------------------------------

SPACE COMPLEXITY:
O(k)

→ map stores at most k distinct characters

------------------------------------------------------------

NOTE:
- Using map gives log factor
- Can be optimized to O(n) using vector/array instead

============================================================
*/

class Solution {
  public:
    int function(string& s,int k){
        if(k<0) return 0;
        map<char,int> mpp;
        int l=0;
        int r=0;
        int cnt=0;

        while(r<s.size()){
            mpp[s[r]]+=1;

            while(mpp.size()>k){
                mpp[s[l]]-=1;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l+=1;
            }

            cnt += r-l+1;
            r+=1;
        }  

        return cnt;
    }

    int countSubstr(string& s, int k) {
        return function(s,k)-function(s,k-1);
    }
};