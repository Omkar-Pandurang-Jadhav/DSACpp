
/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 */


/*
============================================================
LONGEST PALINDROMIC SUBSTRING (2 APPROACHES)
============================================================

PROBLEM:
Find the longest substring of a string that is a palindrome.

============================================================


------------------------------------------------------------
1️⃣ BRUTE FORCE (CHECK ALL SUBSTRINGS)
------------------------------------------------------------

APPROACH:
- Generate all substrings using two loops
- For each substring:
    → check if it is palindrome
- Track the longest valid substring

------------------------------------------------------------

TIME COMPLEXITY:
O(n^3)

→ Outer loops: O(n^2)
→ substring creation: O(n)
→ palindrome check: O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ substring creation uses extra space

------------------------------------------------------------
*/

class Solution {
public:
    bool isPalindrome(string s){
        int n=s.size();
        int i=0;
        while(i<n/2){
            if(s[i]!=s[n-i-1]) return false;
            i++;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int maxlen=-1;
        string ans="";

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(j-i+1>maxlen && isPalindrome(s.substr(i,j-i+1))){
                    ans=s.substr(i,j-i+1);
                    maxlen=j-i+1;
                }
            }
        }

        return ans;
    }
};



/*
------------------------------------------------------------
2️⃣ EXPAND AROUND CENTER (OPTIMAL ⭐)
------------------------------------------------------------

APPROACH:
- Every palindrome expands from a center
- Two cases:
    → odd length (center at i)
    → even length (center between i and i+1)
- Expand while characters match
- Track maximum window

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2)

→ For each index, expansion can go up to n

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

→ No extra space used

------------------------------------------------------------

KEY INSIGHT:
- Avoid generating substrings
- Expand directly using indices

------------------------------------------------------------
*/

class Solution {
public:
    pair<int,int> isPalindrome(string s,int left,int right){
        while(left>-1 && right<s.size() && s[left]==s[right]){
            left-=1;
            right+=1;
        }
        return {left+1,right-1};
    }

    string longestPalindrome(string s) {
        int start=0;
        int end=0;

        for(int i=0;i<s.size();i++){

            // odd length
            auto odd=isPalindrome(s,i,i);
            if(odd.second-odd.first > end-start){
                start=odd.first;
                end=odd.second;
            }

            // even length
            auto even=isPalindrome(s,i,i+1);
            if(even.second-even.first > end-start){
                start=even.first;
                end=even.second;
            }
        }

        return s.substr(start,end-start+1);
    }
};



/*
============================================================
FINAL COMPARISON
============================================================

| Approach                | Time Complexity | Space |
|------------------------|----------------|-------|
| Brute Force            | O(n^3) ❌      | O(n)  |
| Expand Around Center   | O(n^2) ⭐      | O(1)  |

============================================================

INSIGHT:
- Brute force checks all substrings
- Optimal approach expands from center → avoids extra work

============================================================
*/