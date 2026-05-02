
/*
The beauty of a string is the difference in frequencies between the most frequent 
and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"],
 each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17
*/

/*
============================================================
BEAUTY SUM OF ALL SUBSTRINGS (3 APPROACHES)
============================================================

PROBLEM:
For every substring, compute:
    beauty = max frequency - min frequency (only non-zero chars)
Return total beauty sum.

============================================================


------------------------------------------------------------
1️⃣ BRUTE FORCE (MAP + NESTED LOOPS)
------------------------------------------------------------

APPROACH:
- Fix starting index i
- Expand j
- Maintain frequency using map
- For each substring:
    → iterate map to find max & min freq

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2 * 26) ≈ O(n^2)

→ Outer loop: n
→ Inner loop: n
→ Iterating map: at most 26 chars

(Strictly: O(n^2 * log 26 + n^2 * 26))

------------------------------------------------------------

SPACE COMPLEXITY:
O(26) ≈ O(1)

------------------------------------------------------------
*/

class Solution {
public:
    int beautySum(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            map<int,int> mpp;
            for(int j=i;j<s.size();j++){
                mpp[s[j]]+=1;
                int max=0;
                int min=INT_MAX;
                for(auto it:mpp){
                    int count=it.second;
                    if(max<count) max=count;
                    if(min>count) min=count;
                }
                cnt+=max-min;
            }
        }
        return cnt;
    }
};



/*
------------------------------------------------------------
2️⃣ CENTER EXPANSION (YOUR SECOND APPROACH)
------------------------------------------------------------

APPROACH:
- Treat each index as center
- Expand for:
    → odd length (i,i)
    → even length (i,i+1)
- Maintain frequency dynamically while expanding
- Compute beauty at each expansion step

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2 * 26) ≈ O(n^2)

→ Each center expands O(n)
→ Total centers: n
→ Each step: iterate map (≤26)

Total: O(n * n * 26)

------------------------------------------------------------

SPACE COMPLEXITY:
O(26) ≈ O(1)

------------------------------------------------------------

NOTE:
- Generates substrings via expansion
- Same asymptotic complexity as brute force

------------------------------------------------------------
*/

class Solution {
public:
    int frequency(string s,int left,int right){
        int cnt=0;
        map<char,int> mpp;
        while(left>-1 && right<s.size()){
            if(left==right) mpp[s[left]]+=1;
            else {
                mpp[s[left]]+=1;
                mpp[s[right]]+=1;
            }
            int min=INT_MAX;
            int max=0;
            for(auto it:mpp){
                int count=it.second;
                if(max<count) max=count;
                if(min>count) min=count;
            }
            cnt+=max-min;
            left-=1;
            right+=1;
        }
        return cnt;
    }

    int beautySum(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            cnt+=frequency(s,i,i)+frequency(s,i,i+1);
        }
        return cnt;
    }
};



/*
------------------------------------------------------------
3️⃣ OPTIMIZED (VECTOR INSTEAD OF MAP ⭐)
------------------------------------------------------------

APPROACH:
- Same as Approach 1 (fix i, expand j)
- Replace map with vector<int> freq(26)
- Avoid log factor → faster in practice

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2 * 26) ≈ O(n^2)

→ Outer loop: n
→ Inner loop: n
→ Loop over 26 chars

(no log factor)

------------------------------------------------------------

SPACE COMPLEXITY:
O(26) ≈ O(1)

------------------------------------------------------------

BEST PRACTICAL APPROACH

------------------------------------------------------------
*/

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            vector<int> freq(26, 0);

            for(int j = i; j < n; j++){
                freq[s[j]-'a']++;

                int maxFreq = 0;
                int minFreq = INT_MAX;

                for(int k = 0; k < 26; k++){
                    if(freq[k] > 0){
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                cnt += maxFreq - minFreq;
            }
        }

        return cnt;
    }
};



/*
============================================================
FINAL COMPARISON
============================================================

| Approach            | Time Complexity | Space | Note |
|---------------------|----------------|-------|------|
| Map (Brute Force)   | O(n^2)         | O(1)  | log factor hidden |
| Center Expansion    | O(n^2)         | O(1)  | slightly more overhead |
| Vector Optimized    | O(n^2) ⭐      | O(1)  | fastest in practice |

============================================================

FINAL INSIGHT:
- All approaches are O(n^2)
- Optimization only reduces constant factor
- Using vector instead of map is best practical improvement

============================================================
*/